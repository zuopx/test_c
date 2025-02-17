/*
template <int i> struct Int {int a=i;};
constexpr auto iter(Int<0>) -> Int<0>;
template <int i> constexpr auto iter(Int<i>) { return iter(Int<i - 1>{}); }
int main() { decltype(iter(Int<3>{})) a; }

将以上代码在https://cppinsights.io/展开，如下，可知：
-   -> 表示返回值类型
-   constexpr 致使 iter(Int<3>{}) 语句不断展开，直至 iter(Int<0>{}) 结束
-   Int<1>、Int<2> 是不同类型
*/

#include <iostream>
using namespace std;

template<int i>
struct Int
{
  int a = i;
};

/* First instantiated from: insights.cpp:16 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct Int<2>
{
  int a = 2;
};

#endif
/* First instantiated from: insights.cpp:16 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct Int<1>
{
  int a = 1;
};

#endif
/* First instantiated from: insights.cpp:18 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct Int<0>
{
  int a = 0;
  // inline constexpr Int() noexcept = default;
};

#endif
/* First instantiated from: insights.cpp:18 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct Int<3>
{
  int a = 3;
};

#endif

inline constexpr Int<0> iter(Int<0>);

template<int i>
inline constexpr auto iter(Int<i>)
{
  return iter(Int<i - 1>{});
}

#ifdef INSIGHTS_USE_TEMPLATE
template<>
inline constexpr Int<0> iter<3>(Int<3>)
{
  return iter(Int<2>{{2}});
}
#endif


#ifdef INSIGHTS_USE_TEMPLATE
template<>
inline constexpr Int<0> iter<2>(Int<2>)
{
  return iter(Int<1>{{1}});
}
#endif


#ifdef INSIGHTS_USE_TEMPLATE
template<>
inline constexpr Int<0> iter<1>(Int<1>)
{
  return iter(Int<0>{{0}});
}
#endif


#ifdef INSIGHTS_USE_TEMPLATE
template<>
inline constexpr auto iter<0>(Int<0>);
#endif


int main()
{
  Int<0> a = Int<0>();
  std::cout.operator<<(a.a).operator<<(std::endl);
  return 0;
}
