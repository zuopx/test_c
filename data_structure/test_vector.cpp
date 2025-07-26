#include <vector>

int main()
{
    std::vector<int> v;
    v.pop_back();  // undefined behavior
    v.pop_back();

    return 0;
}
