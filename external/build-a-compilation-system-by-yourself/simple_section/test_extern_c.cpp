/*
c++filt _ZN6myname3varE --> myname::var
*/

#include <stdio.h>

namespace myname
{
    int var = 1;
}

extern "C" int _ZN6myname3varE;  // c++filt _ZN6myname3varE --> myname::var

int main()
{
    printf("%d\n", _ZN6myname3varE);  // 1
    return 0;
}