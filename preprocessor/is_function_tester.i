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
