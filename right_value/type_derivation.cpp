/*
C++11引入如下2条规则：

1，模板函数对右值引用参数的推导：
向一个模板函数传递一个左值实参，同时该模板函数的对应形参是右值引用，编译器会把该实参推导为左值引用。
无论模板参数是什么类型的引用，当且仅当实参类型为右引用时，模板参数才能被推导为右引用类型。

2，引用折叠（Reference Collapsing）：
C++中会出现“引用的引用”（reference to reference），
“引用的引用”包括如下4种情况：Lvalue reference to Rvalue reference，Lvalue reference to Lvalue reference，Rvalue reference to Lvalue reference，Rvalue reference to Rvalue reference。
由于C++不允许“引用的引用”，编译器会根据引用折叠规则将这4种情况转变为single reference。其中，前3种情况会转化为左值引用，后1种情况会转化为右值引用。
也就是说，T& &&，T&& &，T& &会转化为T&，T&& &&会转化为T&&。
*/

template <typename T> void f(T &&){};
int i = 10;

int main()
{
    f(i);  // i为左值实参，将被推导为左值引用，模板函数将被实例化为f<int&>(int&)
}


// https://cppinsights.io/ 将上述代码贴到该网页，展开为成下面的代码：
/*
template<typename T>
void f(T &&) {}

#ifdef INSIGHTS_USE_TEMPLATE
template<>
void f<int &>(int &) {}
#endif

int i = 10;

int main()
{
  f(i);
  return 0;
}
*/
