// - **`std::map`**: 
//   - Uses a Red-Black Tree.
//   - Elements are ordered by key.
//   - O(log n) complexity for insertion, deletion, and search.
//   - Best when you need elements to be in a sorted order.

// - **`std::unordered_map`**:
//   - Uses a hash table.
//   - Elements are not ordered.
//   - Average O(1) complexity for insertion, deletion, and search.
//   - Best when you need fast access to elements by key and do not care about order.

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    map<int, string> m1;
    m1[2] = "two";
    m1[1] = "one";
    m1[3] = "three";

    unordered_map<int, string> m2;
    m2[2] = "two";
    m2[1] = "one";
    m2[3] = "three";

    cout << "map:" << endl;
    for (auto& pair : m1)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    cout << "unordered_map:" << endl;
    for (auto& pair : m2)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    return 0;
}
