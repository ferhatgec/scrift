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
    fchar CPUInfo() {
        printlnf("CPU Core: ");
        std::cout << sysconf(_SC_NPROCESSORS_ONLN) << std::endl;
    }
    fchar RAMInfo() {
        printlnf("(Long) RAM: ");
        std::cout << sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE) << std::endl;
        printlnf("(Long) Available: ");
        std::cout << sysconf(_SC_AVPHYS_PAGES) << std::endl;
        printlnf("(Long) Available Page Size: ");
        std::cout << sysconf(_SC_PAGE_SIZE) << std::endl;
    }

} fkernel;

#endif // KERNEL_NAME_HPP