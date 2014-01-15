#include <iostream>
#include <dlfcn.h>
#include <string>

int main ( int argc, char *argv[] )
{

    void * test_lib ;
    std::string lib_name = "";
    std::cout << "Enter name of so to load in the form ./libname.so" << std::endl;
    std::getline(std::cin, lib_name);
    if (lib_name.size() == 0){
        std::cout << "Error: libname not entered, using ./libhello.so as this should work" << std::endl;
        lib_name="./libhello.so";
    }

    //RTLD_LAZY => lazy loading aka don't try to resolve all symbols as soon as loaded wait till they are called
    test_lib = dlopen(lib_name.c_str(), RTLD_LAZY);

    const char * err_msg = dlerror();
    if(err_msg) {
        std::cout << "load so error:" << err_msg << std::endl;
        return -1;
    }

    void (* lib_function) () =
         (void(*) ()) dlsym(test_lib,"say_hello");

    if(err_msg) {
        std::cout << "load so fun:" << err_msg << std::endl;
        return -1;
    }
    lib_function();
    return 0;
}
