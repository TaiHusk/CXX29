# C++ 29

This is a C++ Library header for the upcoming C++29 standard, providing a set of utility functions for working with `std::vector`. The library is currently in the experimental stage and is subject to change.

## Installation

To install the library, copy the `29` directory to your system's include directory:

```
cp -r ./29 /usr/include/c++/
```

# `experimental/smart_view_vector`
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

## `find()` `findIndex()`
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

## `filter()`
The `filter` function is a utility function that creates a new vector containing only the elements from the original vector that satisfy a given condition. The condition is specified using a callback function.

Here is an example usage of the `filter` function:
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
std::vector<int> filtered_vec = smart_view_vector::filter(vec, std::function<bool(const int&)>([](const int& num) { return num % 2 == 0; }));
std::cout << smart_view_vector::to_string(filtered_vec) << std::endl;  // Output: "{2, 4}"
```
The `filter` function can be useful when you need to extract a subset of elements from a vector based on some condition.

## `each()`
The `each` function is a utility function that can be used to iterate over the elements in a vector and apply a callback function to each element.

The `each` function takes a vector and a callback function as arguments. It iterates over the elements in the vector and applies the callback function to each element, passing the element, its index, and the entire vector as arguments to the callback function.

Here is an example usage of the `each` function:
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

std::smart_view::vector::each(vec, std::function<void(const int&, const size_t&, const std::vector<int>&)>([](const int& num, const size_t& index, const std::vector<int>& vec) {
    std::cout << "Element " << num << " at index " << index << " in vector " << smart_view_vector::to_string(vec) << std::endl;
}));
```
This will output:
```log
Element 1 at index 0 in vector {1, 2, 3, 4, 5}
Element 2 at index 1 in vector {1, 2, 3, 4, 5}
Element 3 at index 2 in vector {1, 2, 3, 4, 5}
Element 4 at index 3 in vector {1, 2, 3, 4, 5}
Element 5 at index 4 in vector {1, 2, 3, 4, 5}
```

## `to_string()`
The `each` function can be useful when you need to perform some operation on each element in a vector, but you don't need to modify the vector itself.

The `to_string` function is a utility function that converts a vector to a string representation. The string representation consists of the elements of the vector enclosed in curly braces `{}` and separated by commas `,`.

Here is an example usage of the `to_string` function:
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
std::string str = smart_view_vector::to_string(vec);
std::cout << str << std::endl;  // Output: "{1, 2, 3, 4, 5}"
```
The `to_string` function can be useful when you need to convert a vector to a string for debugging or logging purposes.

# `experimental/smart_view_string`
## Usage

To use the library, include the header file in your C++ source code:
```cpp
#include <c++/29/experimental/smart_view_string>
```

This is a header file for the `smart_view_string` namespace, which provides utility functions for working with `std::string` objects in C++. The header file is part of the GNU ISO C++ Library and is released under the terms of the GNU General Public License.

The `smart_view_string` namespace contains the following functions:

* `startsWith(const std::string &str, const std::string &prefix)`: Returns `true` if the `str` starts with the `prefix`, and `false` otherwise.
* `endsWith(const std::string &str, const std::string &suffix)`: Returns `true` if the `str` ends with the `suffix`, and `false` otherwise.
* `split(const std::string &str, char delimiter)`: Splits the `str` into a vector of substrings based on the `delimiter` character.

Here is an example usage of these functions:
```cpp
#include <iostream>
#include <vector>
#include <c++/29/experimental/smart_view_string>

int main() {
    std::string str = "Hello, World!";

    if (smart_view_string::startsWith(str, "Hello")) {
        std::cout << "String starts with 'Hello'" << std::endl;
    }

    if (smart_view_string::endsWith(str, "World!")) {
        std::cout << "String ends with 'World!'" << std::endl;
    }

    std::vector<std::string> tokens = smart_view_string::split(str, ',');
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}
```
This will output:
```log
String starts with 'Hello'
String ends with 'World!'
Hello
 World!
```

# `experimental/smart_view`
## Usage

To use the library, include the header file in your C++ source code:
```cpp
#include <c++/29/experimental/smart_view>
```

This is a header file for the `smart_view` namespace, which is a part of the GNU ISO C++ Library. The `smart_view` namespace provides utility functions for working with `std::string` and `std::vector` objects in C++.

The `smart_view` namespace contains two sub-namespaces:

* `string`: Contains utility functions for working with `std::string` objects.
* `vector`: Contains utility functions for working with `std::vector` objects.

The `smart_view` namespace is included in the `std` namespace, so you can access its functions directly through the `std::smart_view` namespace.

Here is an example usage of the `smart_view` namespace:
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <c++/29/experimental/smart_view>

int main() {
    std::string str = "Hello, World!";

    if (std::smart_view::string::startsWith(str, "Hello")) {
        std::cout << "String starts with 'Hello'" << std::endl;
    }

    if (std::smart_view::string::endsWith(str, "World!")) {
        std::cout << "String ends with 'World!'" << std::endl;
    }

    std::vector<std::string> tokens = std::smart_view::string::split(str, ',');
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::optional<int> result = std::smart_view::vector::find(vec, std::function<bool(const int&)>([](const int& num) { return num % 2 == 0; }));
    if (result.has_value()) {
        std::cout << "First even number is " << *result << std::endl;
    }

    return 0;
}
```
This will output:
```log
String starts with 'Hello'
String ends with 'World!'
Hello
 World!
First even number is 2
```

## License

This library is distributed under the GNU General Public License, version 3 or later.

## Disclaimer

This library is in the experimental stage and is subject to change. Use it at your own risk.
