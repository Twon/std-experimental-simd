#ifndef STD_EXPERIMENTAL_SIMD_PLATFORM_HPP
#define STD_EXPERIMENTAL_SIMD_PLATFORM_HPP

#pragma once

#include <simd_compiler_detection.h>


#if defined(_M_IX86) || defined(i386) || defined(__i386) || defined(__i386__) || defined(_X86_) || defined(__X86__) || defined(__I86__) || defined(__INTEL__) || defined(__THW_INTEL__)
    #define SIMD_ARCHITECTURE_X86
#elif defined(_M_X64) || defined(_M_AMD64) || defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
    #define SIMD_ARCHITECTURE_X64
#elif defined(_M_IA64) || defined(__itanium__) || defined(__ia64) || defined(__ia64__) || defined(_IA64) || defined(__IA64__)
    #define SIMD_ARCHITECTURE_IA64
#elif defined(_M_ARM) || defined(_M_ARMT) || defined(__arm__) ||  defined(__thumb__) || defined(__arm) || defined(_ARM)
    #define SIMD_ARCHITECTURE_ARM
#elif defined(_M_MRX000) || defined(_MIPS_) || defined(_MIPS64) || defined(__mips__) || defined(__mips) || defined(__MIPS__)
    #if defined(__mips) && (__mips == 64)
        #define SIMD_ARCHITECTURE_ARM64
    #else
        #define SIMD_ARCHITECTURE_ARM32
    #endif
#elif defined(__sparc__) || defined(__sparc)
    #define SIMD_ARCHITECTURE_SPARC
#elif defined(__PPC64__) || defined(_ARCH_PPC64) || defined(__powerpc64__)
    #define SIMD_ARCHITECTURE_PPC64
#elif defined(_M_PPC) || defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__)
    #define SIMD_ARCHITECTURE_PPC32
#endif

#endif //STD_EXPERIMENTAL_SIMD_PLATFORM_HPP
