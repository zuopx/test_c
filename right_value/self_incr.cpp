/*
i++ -> i
++i -> &i

# gcc -o self._incr.out self._incr.cpp

self._incr.cpp: In function ‘int main()’:
self._incr.cpp:9:6: error: lvalue required as left operand of assignment
    9 |     i++ = 2;
      |     ~^~

++i 返回引用（左值）
i++ 返回实例（右值），也因此可能多一层构造临时对象的开销
*/
#include <stdio.h>

int main()
{
    int i =0;
    ++i = 2;
    printf("%i\n", i);

    // i++ = 2;  // error: lvalue required as left operand of assignment

    return 0;
}
