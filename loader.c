#include <iostream>
#include <dlfcn.h>

int main ( int argc, char *argv[] )
{

    void * test_lib ;
    //RTLD_LAZY => lazy loading aka don't try to resolve all symbols as soon as loaded wait till they are called
    test_lib = dlopen("./libhello.so", RTLD_LAZY);

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
