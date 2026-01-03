/*std::move返回右值引用，表示让出对象的所有权，允许资源被移动而不是被复制，但不强制要求必须移动

g++ -o 3.6.1.move.semantics.out 3.6.1.move.semantics.cpp
*/
#include <iostream> // std::cout
#include <vector>
#include <algorithm>

using namespace std;

// 使用了右值引用，没有被移动，等同于普通引用
void sort_vector1(vector<int> &&v)
{
    std::sort(v.begin(), v.end());
}

// 使用了右值引用，确实被移动
void sort_vector2(vector<int> &&v)
{
    auto v_copy = std::move(v);
    std::sort(v_copy.begin(), v_copy.end());
}

int main()
{
    vector<int> v1{5, 3, 8, 1, 4};

    sort_vector1(std::move(v1));

    for (const auto &i : v1)
    {
        cout << i << " "; // 1 3 4 5 8
    }
    cout << endl;

    vector<int> v2{5, 3, 8, 1, 4};

    sort_vector2(std::move(v2));

    for (const auto &i : v2)
    {
        cout << i << " "; // 无输出
    }
    cout << endl;

    return 0;
}