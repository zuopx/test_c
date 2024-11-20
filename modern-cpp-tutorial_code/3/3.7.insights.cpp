#include <iostream>
#include <utility>
#define INSIGHTS_USE_TEMPLATE

void reference(int & v)
{
  std::operator<<(std::cout, "lvalue reference").operator<<(std::endl);
}

void reference(int && v)
{
  std::operator<<(std::cout, "rvalue reference").operator<<(std::endl);
}

template<typename T>
void pass(T && v)
/* 无论模板参数是什么类型的引用，当且仅当实参类型为右引用时，模板参数才能被推导为右引用类型。*/
{
  std::operator<<(std::cout, "          normal param passing: ");
  reference(v);
  std::operator<<(std::cout, "       std::move param passing: ");
  reference(std::move(v));
  std::operator<<(std::cout, "    std::forward param passing: ");
  reference(std::forward<T>(v));
  std::operator<<(std::cout, "static_cast<T&&> param passing: ");
  reference(static_cast<T &&>(v));
}

/* First instantiated from: insights.cpp:36 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void pass<int>(int && v)
{
  std::operator<<(std::cout, "          normal param passing: ");
  reference(v);
  std::operator<<(std::cout, "       std::move param passing: ");
  reference(std::move(v));
  std::operator<<(std::cout, "    std::forward param passing: ");
  reference(std::forward<int>(v));
  std::operator<<(std::cout, "static_cast<T&&> param passing: ");
  reference(static_cast<int &&>(v));
}
#endif


/* First instantiated from: insights.cpp:40 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void pass<int &>(int & v)
{
  std::operator<<(std::cout, "          normal param passing: ");
  reference(v);
  std::operator<<(std::cout, "       std::move param passing: ");
  reference(std::move(v));
  std::operator<<(std::cout, "    std::forward param passing: ");
  reference(std::forward<int &>(v));
  std::operator<<(std::cout, "static_cast<T&&> param passing: ");
  reference(static_cast<int &>(v));
}
#endif


int main()
{
  std::operator<<(std::cout, "rvalue pass:").operator<<(std::endl);
  pass(1);
  std::operator<<(std::cout, "lvalue pass:").operator<<(std::endl);
  int l = 1;
  pass(l);
  return 0;
}
