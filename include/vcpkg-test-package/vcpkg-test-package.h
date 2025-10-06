#ifndef VCPKG_TEST_PACKAGE_H
#define VCPKG_TEST_PACKAGE_H

#include <string>

namespace vcpkg_test_package {

/**
 * @brief Returns the version of vcpkg-test-package
 * @return Version string
 */
inline std::string version() {
    return "0.0.1";
}

/**
 * @brief Returns information about the package
 * @return Package information string
 */
inline std::string info() {
    return "vcpkg-test-package v" + version() + " - Placeholder package for future updates";
}

} // namespace vcpkg_test_package

#endif // VCPKG_TEST_PACKAGE_H