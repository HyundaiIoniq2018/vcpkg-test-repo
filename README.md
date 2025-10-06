# vcpkg-test-package

Placeholder package for future updates - coming soon.

## Installation

### Using vcpkg

```bash
vcpkg install vcpkg-test-package
```

### Using CMake

```bash
git clone https://github.com/HyundaiIoniq2018/vcpkg-test-repo.git
cd vcpkg-test-repo
mkdir build && cd build
cmake ..
cmake --build .
cmake --install .
```

## Usage

```cpp
#include <vcpkg-test-package/vcpkg-test-package.h>
#include <iostream>

int main() {
    std::cout << vcpkg_test_package::info() << std::endl;
    return 0;
}
```

## License

Licensed under the Apache License, Version 2.0. See [LICENSE](LICENSE) for details.

## Author

Guy Morad (guymorad310@gmail.com)

## Status

This is a placeholder package. More functionality coming soon!