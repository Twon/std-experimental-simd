find_package(Doxygen)

option(ENABLE_BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(ENABLE_BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(DOXYGEN_PROJECT_NAME "std::experimental::simd")
    set(DOXYGEN_EXTENSION_MAPPING "no_extension=C++")

    doxygen_add_docs(Documentation
            ${CMAKE_CURRENT_SOURCE_DIR}/simd/simd # Force inclusion of simd header with no extension
            ${CMAKE_CURRENT_SOURCE_DIR}/simd
        WORKING_DIRECTORY
            ${PROJECT_SOURCE_DIR}/simd/
        COMMENT
            "Generating API documentation with Doxygen"
    )

    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION ${CMAKE_INSTALL_DOCDIR})

    set_target_properties(Documentation PROPERTIES FOLDER ${STD_EXPERIMENTAL_SIMD_PREDEFINED_TARGETS})
endif()