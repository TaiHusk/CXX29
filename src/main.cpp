#include <iostream>
#include <format>
#include <c++/29/experimental/smart_view_vector>

int main() {
    smart_view_vector::print(std::vector<uint>{2, 3, 4, 5});
    std::cout << std::format("includes: {0}", smart_view_vector::includes({1, 3, 4}, std::function<bool(const int&)>([](const int& num){ return num % 2 == 0; }))) << std::endl;
    std::cout << std::format("every: {0}", smart_view_vector::every({1, 3, 4}, std::function<bool(const int&)>([](const int& num){ return num % 2 == 0; }))) << std::endl;
    std::cout << std::format("{0}", smart_view_vector::every({2, 2, 2}, std::function<bool(const int&)>([](const int& num){ return num % 2 == 0; }))) << std::endl;
}
