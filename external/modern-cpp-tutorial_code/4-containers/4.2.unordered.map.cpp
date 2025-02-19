//
// 4.2.unordered.map.cpp
// chapter 04 containers
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main() {
  // initialized in same order
  std::unordered_map<int, std::string> u = {{1, "1"}, {3, "3"}, {2, "2"}};
  std::map<int, std::string> v = {{1, "1"}, {3, "3"}, {2, "2"}};

  // iterates in the same way
  std::cout << "std::unordered_map" << std::endl;
  for (const auto &n : u)
    std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";

  std::cout << std::endl;
  std::cout << "std::map" << std::endl;
  for (const auto &n : v)
    std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}


/*
g++ -o 4.2.unordered.map.out 4.2.unordered.map.cpp

| Feature                       | `std::map`                         | `std::unordered_map`                 |
|-------------------------------|------------------------------------|--------------------------------------|
| **Implementation**            | Balanced binary search tree (e.g., Red-Black Tree) | Hash table                        |
| **Order of Elements**         | Elements are sorted by key         | No specific order; elements may appear in any order |
| **Time Complexity (Average)** | O(log n) for insertions, deletions, lookups | O(1) for insertions, deletions, lookups |
| **Time Complexity (Worst)**   | O(log n)                           | O(n) in case of many hash collisions |
| **Key Requirements**          | Keys must be comparable (e.g., must support `<`) | Keys must be hashable (needs a hash function) |
| **Memory Overhead**           | Generally higher due to tree structure | Generally lower, but can vary based on load factor |
| **Use Cases**                 | When you need sorted elements or range queries | When fast access is important and order does not matter |
| **Iteration Order**           | In-order traversal (sorted order)  | No guaranteed order; depends on hash function |
| **Memory Management**         | Uses node-based memory allocation   | Can allocate memory in blocks, depending on the implementation |
| **Default Comparators/Hashers**| Uses `std::less<Key>`               | Uses `std::hash<Key>` (can use custom hash functions) |
| **Performance under Load**    | Performance remains stable          | Performance can degrade if the load factor is high (many elements relative to buckets) |
*/
