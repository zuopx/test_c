/*boost宏展开示例

https://www.boost.org/doc/libs/1_86_0/libs/preprocessor/doc/index.html

In practice, preprocessor metaprogramming is far simpler and more portable than template metaprogramming.

g++ -E -P -I/root/project/c/boost_1_85_0 -o is_function_tester.i is_function_tester.cpp
clang-format -i --style="{ColumnLimit: 120}" is_function_tester.i

template <class R> yes_type is_function_tester(R (*)());
template <class R, class A0> yes_type is_function_tester(R (*)(A0));
template <class R, class A0, class A1> yes_type is_function_tester(R (*)(A0, A1));
template <class R, class A0, class A1, class A2> yes_type is_function_tester(R (*)(A0, A1, A2));
template <class R, class A0, class A1, class A2, class A3> yes_type is_function_tester(R (*)(A0, A1, A2, A3));
template <class R, class A0, class A1, class A2, class A3, class A4>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,
          class A10>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,
          class A10, class A11>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,
          class A10, class A11, class A12>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,
          class A10, class A11, class A12, class A13>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13));
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,
          class A10, class A11, class A12, class A13, class A14>
yes_type is_function_tester(R (*)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14));
*/

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition.hpp>

#ifndef MAX_IS_FUNCTION_TESTER_PARAMS
#define MAX_IS_FUNCTION_TESTER_PARAMS 15
#endif

// BOOST_PP_ENUM_PARAMS(count, param) -> param ## 0, param ## 1, ... param ## count - 1
#define IS_FUNCTION_TESTER(Z, N, _) \
   template<class R BOOST_PP_COMMA_IF(N) BOOST_PP_ENUM_PARAMS(N, class A)> \
   yes_type is_function_tester(R (*)(BOOST_PP_ENUM_PARAMS(N, A))); \
   /**/

// BOOST_PP_REPEAT(count, macro, data) -> macro(z, 0, data) macro(z, 1, data) ... macro(z, count - 1, data)
BOOST_PP_REPEAT(BOOST_PP_INC(MAX_IS_FUNCTION_TESTER_PARAMS), IS_FUNCTION_TESTER, _)

#undef IS_FUNCTION_TESTER
