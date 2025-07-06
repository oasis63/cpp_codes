#include <iostream>

int main() {
    // Check for the C++ standard version using the __cplusplus macro
    if (__cplusplus == 201103L)
        std::cout << "C++11\n";
    else if (__cplusplus == 201402L)
        std::cout << "C++14\n";
    else if (__cplusplus == 201703L)
        std::cout << "C++17\n";
    else if (__cplusplus == 202002L)
        std::cout << "C++20\n";
    else if (__cplusplus > 202002L)
        std::cout << "C++23 or later\n";
    else
        std::cout << "Pre C++11 or unknown\n";

    return 0;
}
