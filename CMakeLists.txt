cmake_minimum_required(VERSION 3.14)
project(vcpkg-test-package VERSION 0.0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create interface library (header-only)
add_library(vcpkg-test-package INTERFACE)
add_library(vcpkg-test-package::vcpkg-test-package ALIAS vcpkg-test-package)

# Specify include directories
target_include_directories(vcpkg-test-package
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Installation
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS vcpkg-test-package
    EXPORT vcpkg-test-package-targets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT vcpkg-test-package-targets
    FILE vcpkg-test-package-targets.cmake
    NAMESPACE vcpkg-test-package::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vcpkg-test-package
)

# Create config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/vcpkg-test-package-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/vcpkg-test-package-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vcpkg-test-package
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/vcpkg-test-package-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vcpkg-test-package-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/vcpkg-test-package-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vcpkg-test-package
)