cmake_minimum_required(VERSION 3.14)

if(NOT DEFINED PROJECT_NAME)
    set(STD_EXPERIMENTAL_SIMD_IS_NOT_SUBPROJECT ON)
endif()

file(STRINGS "version.txt" STD_EXPERIMENTAL_SIMD_VERSION)

project(std_experimental_simd
    VERSION ${STD_EXPERIMENTAL_SIMD_VERSION}
    DESCRIPTION "A reference implementation of the proposed std::experimental::simd data type for parallel programming"
    LANGUAGES CXX
)

# Include necessary submodules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# CMake includes
include(CTest)
include(FetchContent)
include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakeDependentOption)
include(CMakePackageConfigHelpers)
include(WriteCompilerDetectionHeader)

set(STD_EXPERIMENTAL_SIMD_PREDEFINED_TARGETS "_BuildTargets")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER ${STD_EXPERIMENTAL_SIMD_PREDEFINED_TARGETS})

# Project includes
include(Documentation)

# Ensure code coverage is switched off for Mac OS until the code coverage library addresses the AppleClang issue
cmake_dependent_option(ENABLE_CODE_COVERAGE "Enable code coverage" ON "\"${CMAKE_CXX_COMPILER_ID}\" STREQUAL \"Clang\" OR \"${CMAKE_CXX_COMPILER_ID}\" STREQUAL \"GNU\"" OFF)


add_library(std_experimental_simd INTERFACE)
target_include_directories(std_experimental_simd
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:{CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(std_experimental_simd
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/experimental/simd>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/experimental/simd_platform.hpp>
        $<INSTALL_INTERFACE:{CMAKE_INSTALL_INCLUDEDIR}/experimental/simd>
        $<INSTALL_INTERFACE:{CMAKE_INSTALL_INCLUDEDIR}/experimental/simd_platform.hpp>
)

target_compile_features(std_experimental_simd
    INTERFACE
        cxx_std_17
)

# namespaced alias for users depending on std_experimental_simd as a sub-project.
add_library(std_experimental_simd::std_experimental_simd ALIAS std_experimental_simd)

write_compiler_detection_header(
    FILE experimental/simd_compiler_detection.h
    PREFIX STD_EXPERIMENTAL_SIMD
    COMPILERS GNU Clang MSVC Intel AppleClang
    FEATURES cxx_constexpr
)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
#generate_export_header(std_experimental_simd BASE_NAME experimental/simd)

if(STD_EXPERIMENTAL_SIMD_IS_NOT_SUBPROJECT)

    if (${BUILD_TESTING})
        FetchContent_Declare(
            catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        )

        FetchContent_GetProperties(catch2)
        if(NOT catch2_POPULATED)
            FetchContent_Populate(catch2)
            add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
        endif()

        add_executable(test_std_experimental_simd "")
        target_sources(test_std_experimental_simd
            PRIVATE
                experimental/simd.test.cpp
        )

        target_link_libraries(test_std_experimental_simd
            PRIVATE
                std_experimental_simd::std_experimental_simd
                Catch2::Catch2
        )

        target_compile_options(test_std_experimental_simd
            PRIVATE
                $<$<CXX_COMPILER_ID:MSVC>:/W4>
                $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Werror;-Wall>
        )

        set_target_properties(test_std_experimental_simd PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
        )

        enable_testing()
        add_test(
            NAME test_std_experimental_simd
            COMMAND test_std_experimental_simd
            WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        )

        list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
        include(Catch)
        catch_discover_tests(test_std_experimental_simd)
    endif(${BUILD_TESTING})

    if (ENABLE_CODE_COVERAGE)
        FetchContent_Declare(
            codecoverage
            GIT_REPOSITORY https://github.com/RWTH-HPC/CMake-codecov.git
        )

        FetchContent_GetProperties(codecoverage)
        if(NOT codecoverage_POPULATED)
            FetchContent_Populate(codecoverage)
            list(APPEND CMAKE_MODULE_PATH ${codecoverage_SOURCE_DIR}/cmake)
        endif()

        set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
        find_package(codecov)
        add_coverage(test_std_experimental_simd)
        list(APPEND LCOV_REMOVE_PATTERNS "'/usr/*'")
        coverage_evaluate()
    endif()

# Hierarchically copy headers to the install dir
install (
    DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/experimental"
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/experimental
    FILES_MATCHING PATTERN
        "*.hpp"
)

install(
    FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/simd_export.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/simd_compiler_detection.h"
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/experimental
)

install(TARGETS std_experimental_simd
        EXPORT std_experimental_simd-target
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT std_experimental_simd-target
    NAMESPACE std_experimental_simd::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/std_experimental_simd"
)

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

endif(STD_EXPERIMENTAL_SIMD_IS_NOT_SUBPROJECT)