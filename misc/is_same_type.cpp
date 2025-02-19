#include <iostream>
#include <type_traits>

int main() {
    // Check if int and int are the same
    std::cout << std::boolalpha; // Print bool as true/false
    std::cout << "int and int: " << std::is_same<int, int>::value << std::endl; // true

    // Check if int and float are the same
    std::cout << "int and float: " << std::is_same<int, float>::value << std::endl; // false

    // Check if pointer types are the same
    std::cout << "int* and int*: " << std::is_same<int*, int*>::value << std::endl; // true
    std::cout << "int* and float*: " << std::is_same<int*, float*>::value << std::endl; // false

    return 0;
}
