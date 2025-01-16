#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type print(T value)
{
  (std::operator<<(std::cout, "Integral value: ") << value) << std::endl;
}

/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename std::enable_if<std::is_integral<int>::value, void>::type print<int>(int value)
{
  std::operator<<(std::cout, "Integral value: ").operator<<(value).operator<<(std::endl);
}
#endif


/* First instantiated from: insights.cpp:19 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename std::enable_if<std::is_integral<char>::value, void>::type print<char>(char value)
{
  std::operator<<(std::operator<<(std::cout, "Integral value: "), value).operator<<(std::endl);
}
#endif


template<typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type print(T value)
{
  std::operator<<(std::cout, "Not an integral value.").operator<<(std::endl);
}

/* First instantiated from: insights.cpp:18 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename std::enable_if<!std::is_integral<double>::value, void>::type print<double>(double value)
{
  std::operator<<(std::cout, "Not an integral value.").operator<<(std::endl);
}
#endif


int main()
{
  print(42);
  print(3.1400000000000001);
  print('A');
  return 0;
}
