#include <vector>
using namespace std;

std::vector<int> foo() {
    std::vector<int> temp = {1, 2};
    return temp;
}

int main()
{
    std::vector<int> v = foo();
    return 0;
}
