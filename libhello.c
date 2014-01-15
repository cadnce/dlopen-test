#include <iostream>


//Must be defined as extern "C" otherwise c++ name mangling
extern "C" void say_hello() 
{
    std::cout << "libhello says HELLO!\n" << std::endl;
}
