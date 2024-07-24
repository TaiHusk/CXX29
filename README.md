# C++ 29

This is a C++ Library header for the upcoming C++29 standard, providing a set of utility functions for working with `std::vector`. The library is currently in the experimental stage and is subject to change.

## Headers
- [`experimental/smart_view_vector`](#experimentalsmart_view_vector)
- [`experimental/smart_view_string`](#experimentalsmart_view_string)
- [`experimental/smart_view`](#experimentalsmart_view)
- [`reflect`](#reflect)
  - [`reflect::construct`](#reflect-construct)
  - [`reflect::ownership`](#reflect-ownership)
- [`vector_ptr`](#vector_ptr)

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

# `reflect`
## Usage

To use the library, include the header file in your C++ source code:
```cpp
#include <c++/29/reflect>
```

This is a header file for a `reflect` class that provides a set of static member functions for performing runtime type identification and downcasting of polymorphic objects. The class is designed to be used in a C++29 environment, as indicated by the `__cxx29` namespace.

<a id="reflect-construct"></a>

## `construct()`
The `reflect` class has three template functions called `construct`. Each function takes a pointer or reference to an object of some abstract type `_Abstract` and attempts to dynamic cast it to a pointer of type `T`.

The first function takes a pointer to an object, the second function takes a reference to an object, and the third function takes a `unique_ptr` to an object.

If the dynamic cast is successful, the function returns a pointer to the object of type `T`. If the dynamic cast fails, the function returns a null pointer.

> [!TIP]
> The `reflect` class can be useful when you need to perform runtime polymorphism and you want to avoid using `dynamic_cast` directly in your code. By using the `reflect` class, you can centralize all the dynamic casting in one place and make your code more readable and maintainable.

To use the `reflect` class, you can include the header file in your source code and use the `construct` function. Here is an example usage:
```cpp
#include <iostream>
#include <memory>
#include <c++/29/reflect>

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    std::unique_ptr<Shape> shape = std::make_unique<Circle>();
    const Circle* circle = std::reflect::construct<Circle>(shape);

    if (circle != nullptr) {
        circle->draw();  // Output: "Drawing a circle"
    }

    std::unique_ptr<Shape> shape2 = std::make_unique<Square>();
    const Circle* circle2 = std::reflect::construct<Circle>(shape2);
    
    if (circle2 != nullptr) {
        circle2->draw();  // This code will not be executed because the dynamic cast will fail
    }

    return 0;
}
```
In this example, we have an abstract class `Shape` and two concrete classes `Circle` and `Square` that inherit from `Shape`. We use the `reflect::construct` function to dynamic cast a `unique_ptr<Shape>` to a `Circle*`. If the dynamic cast is successful, we call the `draw` function on the `Circle` object. If the dynamic cast fails, we do nothing.

<a id="reflect-ownership"></a>

## `ownership()`
### What is `ownership()` ?

The `ownership` method is designed to perform dynamic type casting (dynamic cast) of objects managed by smart pointers or regular pointers. It allows for the safe conversion of a pointer to a base class into a pointer to a derived class, if possible.

### What does the `ownership` method do?

The `ownership` method uses `dynamic_cast` to convert a pointer to a base class into a pointer to a derived class. If the conversion is possible, the method returns a pointer to the derived class. If the conversion is not possible (for example, if the object is not an instance of the derived class), the method returns `nullptr`.

The `ownership` method supports both const and non-const pointers, as well as smart pointers. It considers the constness of the input pointer and returns the corresponding pointer type (const or non-const).

### What is the `ownership` method intended for?

The `ownership` method is intended for performing dynamic type casting and supporting both const and non-const pointers, as well as smart pointers. It allows for the safe conversion of a pointer to a base class into a pointer to a derived class, if possible. This is particularly useful in scenarios where access to the methods and data of the derived class is needed, which are not accessible through the base class interface.

### Useful `operations` with `ownership`
1. **Access to derived class methods**: The `ownership` method allows access to the methods of the derived class, which are not accessible through the base class interface.
2. **Support for constness**: The `ownership` method supports both const and non-const pointers, making it more versatile.
3. **Support for smart pointers**: The `ownership` method supports smart pointers, making it safer and more convenient to use in modern C++ programs.

### Differences between `construct` and `ownership`
1. **Constness**:
    - The `construct` methods always return a const pointer (`const T*`).
    - The `ownership` methods consider the constness of the input pointer and return the corresponding pointer type (const or non-const).

2. **Versatility**:
    - The `construct` methods are less versatile since they always return a const pointer.
    - The `ownership` methods are more versatile since they support both const and non-const pointers, as well as smart pointers.

3. **Use of `constexpr` and `noexcept`**:
    - The `ownership` methods use `constexpr` and `noexcept`, which can improve code performance and safety.
    - The `construct` methods do not use `constexpr` and `noexcept`.

### Overview of using `construct` and `ownership` methods with an example
Take a look at an example of using the `construct` and `ownership` methods to perform dynamic type casting and access methods of a derived class.
```cpp
#include <iostream>
#include <memory>
#include <c++/29/reflect>

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }

    void circleSpecificMethod() const {
        std::cout << "Circle-specific method called" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    // Create a unique_ptr to manage a Circle object
    std::unique_ptr<Shape> shape = std::make_unique<Circle>();

    // Use the ownership function to perform a dynamic cast
    const Circle* circlePtr = std::reflect::ownership<Circle>(std::reflect::construct<Shape>(shape));

    if (circlePtr != nullptr) {
        circlePtr->draw();
        circlePtr->circleSpecificMethod(); // This method is specific to Circle
    }

    // Create another unique_ptr to manage a Circle object
    std::unique_ptr<Shape> anotherShape = std::make_unique<Circle>();

    // Use the ownership function to perform a dynamic cast
    const Circle* anotherCirclePtr = std::reflect::ownership<Circle>(anotherShape);

    if (anotherCirclePtr != nullptr) {
        anotherCirclePtr->draw();
        anotherCirclePtr->circleSpecificMethod(); // This method is specific to Circle
    }
};
```

Output:
```plaintext
Drawing a circle
Circle-specific method called
Drawing a circle
Circle-specific method called
```

<details>
<summary>Explanation of the example</summary>

## Explanation of the example

1. **Creating an object**:
    - A smart pointer `std::unique_ptr<Shape>` is created to manage a `Circle` class object.

2. **Using the `construct` method**:
    - The `construct` method is used to perform dynamic type casting from `std::unique_ptr<Shape>` to `const Shape*`.
    - This step is necessary to obtain a pointer to the base class `Shape`.

3. **Using the `ownership` method**:
    - The `ownership` method is used to perform dynamic type casting from `const Shape*` to `const Circle*`.
    - This step allows obtaining a pointer to the derived class `Circle`.

4. **Checking and calling methods**:
    - It is checked that the `circlePtr` pointer is not `nullptr`.
    - If the pointer is not `nullptr`, the `draw` and `circleSpecificMethod` methods of the `Circle` class object are called.

## Explanation of the key code section

```cpp
const Circle* circlePtr = std::reflect::ownership<Circle>(std::reflect::construct<Shape>(shape));
```

This code section demonstrates the combined use of the `construct` and `ownership` methods to perform dynamic type casting. Let's break it down step by step:

1. **Calling the `construct` method**:
    - The `construct` method takes a smart pointer `std::unique_ptr<Shape>` and performs dynamic type casting to `const Shape*`.
    - This allows obtaining a pointer to the base class `Shape`.

2. **Calling the `ownership` method**:
    - The `ownership` method takes a pointer `const Shape*` and performs dynamic type casting to `const Circle*`.
    - This allows obtaining a pointer to the derived class `Circle`.

</details>

---

> [!NOTE]
> Thus, the combined use of the `construct` and `ownership` methods enables safe and convenient dynamic type casting and access to derived class methods.

### Conclusion
This example demonstrates how the `construct` and `ownership` methods can be used together to perform dynamic type casting and access derived class methods. The `construct` method is used to obtain a pointer to the base class, while the `ownership` method is used to obtain a pointer to the derived class. This approach allows for safe and convenient handling of objects managed by smart pointers.

# `vector_ptr`
## Usage

To use the library, include the header file in your C++ source code:
```cpp
#include <c++/29/vector_ptr>
```
## Overview
The `vector_ptr` library is part of the GNU ISO C++ Library, designed to handle heterogeneous collections of pointers in a type-safe manner. This library facilitates the storage of pointers to objects of different types in a single container, while providing mechanisms to safely cast them back to their original types.

## Features
* **Dynamically Adding Pointers:**  The `push_back()` method allows you to add pointers of various types (including raw pointers, `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`) to the vector.
* **Type-Safe Access:** The `get()` method provides type-safe access to the pointers stored in the vector, preventing potential runtime errors.
* **Resource Management:** The destructor of `vector_ptr` automatically deletes the objects pointed to by the stored pointers, ensuring proper resource cleanup.

## Requirements
- C++17 or higher
- GCC 10.1 or later (for complete C++20 support)
- Standard Template Library (STL)

### Example with [`reflect`](#reflect)
The example utilizes the `reflect` library to create a `const` reference to the `Circle` object. This allows you to access the `draw()` method of the `Circle` object without needing to worry about potential memory issues.
```cpp
#include <iostream>
#include <memory>

#include <c++/29/experimental/smart_view>
#include <c++/29/reflect>
#include <c++/29/vector_ptr>

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    std::vector_ptr vp;

    std::unique_ptr<Shape> shape = std::make_unique<Circle>();
    vp.push_back(shape);

    try {
        Circle* circlePtr = vp.get<0, Circle>();
        const Circle* circle = std::reflect::construct<Circle>(circlePtr);

        circle->draw();

    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
};
```

> [!TIP]
> * **Memory Management:** When using raw pointers with `vector_ptr`, ensure that the objects are properly allocated and deallocated.  The `vector_ptr` destructor will handle deleting the objects, but you need to be responsible for creating them.
> * **Error Handling:** The `get()` method throws an `out_of_range` exception if the index is invalid. It's crucial to handle this exception in your code.


## Full Technique
Here's a breakdown of the `vector_ptr` technique:

* **Purpose:** The `vector_ptr` class serves as a container for managing pointers to objects, providing a safe and efficient way to store and access these pointers.
* **Benefits:**  
    * **Type Safety:**  The `get()` method ensures type safety during access, preventing potential runtime errors.
    * **Resource Management:**  The destructor automatically deallocates the objects pointed to, avoiding memory leaks.
    * **Flexibility:**  It allows storing various pointer types (raw pointers, smart pointers) in a single container.
* **Use Cases:**  The `vector_ptr` technique is particularly useful in scenarios where you need to store pointers to a collection of objects and perform operations on them. This could involve:
    * **Managing a pool of objects:**  This is useful for scenarios like object caching or resource management.
    * **Implementing a factory pattern:**  You can store pointers to different object factories.
    * **Maintaining a list of objects:**  You can use `vector_ptr` to store pointers to objects in a list and efficiently iterate over them.

# License
This library is distributed under the GNU General Public License, version 3 or later.