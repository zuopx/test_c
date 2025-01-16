/*
definition:
    // Primary template.
    /// Define a member typedef @c type only if a boolean constant is true.
    template<bool, typename _Tp = void>
    struct enable_if
    { };

    // Partial specialization for true.
    template<typename _Tp>
    struct enable_if<true, _Tp>
    { typedef _Tp type; };

usage:
    need ‘typename’ before ‘std::enable_if<std::is_integral<_Tp>::value, void>::type’ 
    because ‘std::enable_if<std::is_integral<_Tp>::value, void>’ is a dependent scope
    编译器必须被明确告知这是一个类型
*/


#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
void print(T value) {
    std::cout << "Integral value: " << value << std::endl;
}

template<typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
print(T value) {
    std::cout << "Not an integral value." << std::endl;
}

int main() {
    print(42);        // Integral value
    print(3.14);     // Not an integral value
    print('A');      // Integral value (char is an integral type)

    return 0;
}
