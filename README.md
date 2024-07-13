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

# `find()` `finfIndex()`
- `std::optional<T> find<T>(const std::vector<T>& vec, const std::function<bool(const T&)>& callback)`
- `size_t findIndex<T>(const std::vector<T>& vec, const std::function<bool(const T&)>& callback)`

The `find` and `findIndex` functions are utility functions that can be used to search for an element in a vector that satisfies a given condition.

The `find` function takes a vector and a callback function as arguments. It iterates over the elements in the vector and applies the callback function to each element. The `find` function now returns an `std::optional<T>`. This allows the function to return the actual element that satisfies the condition, or `std::nullopt` if no such element is found.

Here is an example usage of the `find` function:
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
auto result = smart_view_vector::find(vec, std::function<bool(const int&)>([](const int& num) { return num > 3; }));

if (result) {
    std::cout << *result << std::endl; // will return 4
} else {
    std::cout << "No match found" << std::endl;
}
```
The `findIndex` function is similar to the `find` function, but instead of returning the element that satisfies the condition, it returns the index of that element in the vector. If no element satisfies the condition, it returns `-1`.

Here is an example usage of the `findIndex` function:
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
int result = smart_view_vector::findIndex(vec, std::function<bool(const int&)>([](const int& num) { return num < 3; }));
std::cout << result << std::endl;
```
Both functions use a simple linear search algorithm, which has a time complexity of O(n), where n is the size of the vector. If the vector is sorted, a more efficient search algorithm such as binary search can be used to improve the performance.

## License

This library is distributed under the GNU General Public License, version 3 or later.

## Disclaimer

This library is in the experimental stage and is subject to change. Use it at your own risk.
