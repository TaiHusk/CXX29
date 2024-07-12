# C++ 29

This is a C++ Library header for the upcoming C++29 standard, providing a set of utility functions for working with `std::vector`. The library is currently in the experimental stage and is subject to change.

## Installation

To install the library, copy the `29` directory to your system's include directory:

```
cp -r ./29 /usr/include/c++/
```

## Usage

To use the library, include the header file in your C++ source code:

```cpp
#include <c++/29/experimental/smart_view_vector>
```

The library provides the following functions:

* `includes(const std::vector<T>& vec, const bool& value)`: Checks if a vector contains a specific value.
* `includes(const std::vector<T>& vec, const std::function<bool(const T&)>& callback)`: Checks if a vector contains an element that satisfies a given condition.
* `every(const std::vector<T>& vec, const bool& value)`: Checks if all elements in a vector are equal to a specific value.
* `every(const std::vector<T>& vec, const std::function<bool(const T&)>& callback)`: Checks if all elements in a vector satisfy a given condition.
* `print(const std::vector<T>& vec)`: Prints the contents of a vector to the standard output.

Here's an example of how to use the library:

```cpp
#include <iostream>
#include <format>
#include <c++/29/experimental/smart_view_vector>

int main() {
    smart_view_vector::print(std::vector<uint>{2, 3, 4, 5});
    std::cout << std::format("includes: {0}", smart_view_vector::includes({1, 3, 4}, std::function<bool(const int&)>([](const int& num){ return num % 2 == 0; }))) << std::endl;
    std::cout << std::format("every: {0}", smart_view_vector::every({1, 3, 4}, std::function<bool(const int&)>([](const int& num){ return num % 2 == 0; }))) << std::endl;
    std::cout << std::format("{0}", smart_view_vector::every({2, 2, 2}, std::function<bool(const int&)>([](const int& num){ return num % 2 == 0; }))) << std::endl;
}
```

## License

This library is distributed under the GNU General Public License, version 3 or later.

## Disclaimer

This library is in the experimental stage and is subject to change. Use it at your own risk.
