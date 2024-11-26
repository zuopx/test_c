//
// 2.20.strong.type.enum.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
template <typename T>
std::ostream &operator<<(
    typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream,
    const T &e) {
  return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

// there will be compile error if all define value1 和 value2
enum Left { left_value1 = 1, left_value2 };
enum Right { right_value1 = 1, right_value2 };

enum class new_enum : unsigned int {
  value1,
  value2,
  value3 = 100,
  value4 = 100
};

int main() {

  if (Left::left_value1 == Right::right_value2) {
    std::cout << "Left::value1 == Right::value2" << std::endl;
  }

  // compile error
  // if(new_enum::left_value1 == 1) {
  //     std::cout << "true!" << std::endl;
  // }
  if (new_enum::value3 == new_enum::value4) {
    std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
  }

  std::cout << new_enum::value3 << std::endl;

  return 0;
}


/*
g++ -o 2.20.strong.type.enum.out 2.20.strong.type.enum.cpp

**std::enable_if**：
   ```cpp
   typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream
   ```
   这里使用了 `std::enable_if`，它的作用是根据 `std::is_enum<T>::value` 的值来决定这个模板是否有效。
   如果 `T` 是枚举类型，则 `std::enable_if` 返回 `std::ostream` 类型，否则这个重载就不可用。
*/
