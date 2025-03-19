#include <algorithm>
#include <iostream>
#include <vector>

void print(const int &value)
{
    std::cout << value << ",";
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    os << "[";
    std::for_each(vec.begin(), vec.end(), std::cref(print));
    os << "]";
    return os;
}