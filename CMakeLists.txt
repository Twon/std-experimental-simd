cmake_minimum_required(VERSION 3.14)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(STD_EXPERIMENTAL_SIMD_IS_NOT_SUBPROJECT ON)
endif()

file(STRINGS "version.txt" STD_EXPERIMENTAL_SIMD_VERSION)

project(std_experimental_simd
    VERSION ${STD_EXPERIMENTAL_SIMD_VERSION}
    DESCRIPTION "A reference implementation of the proposed std::experimental::simd data type for parallel programming"
    LANGUAGES CXX
)

add_library(std_experimental_simd INTERFACE)
target_include_directories(std_experimental_simd
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_sources(std_experimental_simd
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/simd/simd.h>
        $<INSTALL_INTERFACE:include/simd/simd.h>
)

target_compile_features(std_experimental_simd
    INTERFACE
        cxx_std_14
)

include(WriteCompilerDetectionHeader)
write_compiler_detection_header(
    FILE simd_compiler_detection.h
    PREFIX STD_EXPERIMENTAL_SIMD
    COMPILERS GNU Clang MSVC Intel AppleClang
    FEATURES cxx_constexpr
)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
include(GenerateExportHeader)
#generate_export_header(std_experimental_simd BASE_NAME simd)

include(GNUInstallDirs)
# Hierarchically copy headers to the install dir
install (
    DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/simd"
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/simd
    FILES_MATCHING PATTERN
        "*.hpp"
)

install(
    FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/simd_export.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/simd_compiler_detection.h"
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/simd
)

install(TARGETS std_experimental_simd
        EXPORT std_experimental_simd-target
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION include/simd
)

install(
    EXPORT std_experimental_simd-target
    NAMESPACE std_experimental_simd::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/std_experimental_simd"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/std_experimental_simd-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/std_experimental_simd-config.cmake
    INSTALL_DESTINATION
        "${CMAKE_INSTALL_LIBDIR}/cmake/propagate_const"
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/std_experimental_simd-version.cmake
    VERSION ${PROPAGATE_CONST_VERSION}
    COMPATIBILITY SameMajorVersion
    ARCH_INDEPENDENT
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/std_experimental_simd-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/std_experimental_simd-version.cmake
    DESTINATION
        "${CMAKE_INSTALL_LIBDIR}/cmake/std_experimental_simd"
)
