#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> void print(std::ostream &os, const T &value)
{
    os << value << ",";
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    os << "[";
    std::for_each(vec.begin(), vec.end(), [&os](T value){print<T>(os, value);});
    os << "]";
    return os;
}