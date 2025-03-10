#include <iostream>

int main()
{
    int *p = nullptr;
    std::cout << *p; // 访问空指针，导致崩溃
    return 0;
}

/*
ulimit -c unlimited
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
*/
