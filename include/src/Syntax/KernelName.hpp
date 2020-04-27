#ifndef KERNEL_NAME_HPP
#define KERNEL_NAME_HPP

#include "GetNameFunction.hpp"

typedef struct {
    fchar KernelName() {
    #ifdef _WIN32 // Windows NT IA-32
    printlnf("Windows NT (IA-32) is not supported for Fegeya Scrift");
    #elif _WIN64 // Windows NT AMD64
    printlnf("Windows NT (AMD64) is not supported for Fegeya Scrift");
    #elif __linux__ // Linux Kernel
    printlnf("Linux");
    #elif __FreeBSD__
    printlnf("BSD");
    #elif __APPLE__ || __MACH__
    printlnf("Darwin");
    #elif __unix || __unix__
    printlnf("Unix");
    #else
    printlnf("Fegeya Fusion or not supported OS");
    #endif
    slashn
    }

} fkernel;

#endif // KERNEL_NAME_HPP