// 在 C++ 标准库中，`insert` 和 `emplace` 都用于向容器中添加元素，但它们在处理方式上有所不同。以下是它们之间的主要区别：

// 1. **构造方式**：
//     - `insert`：需要现有的对象或初始值，然后将其复制或移动到容器中。插入过程需要调用拷贝构造函数或移动构造函数。例如，对于一个 `std::vector<int>`，你可以使用 `vec.insert(vec.begin(), 10)`，这会将值为 10 的对象插入到向量的开始位置。
//     - `emplace`：直接在容器中构造对象，避免了不必要的复制或移动。这对于需要传递多个参数构造对象的场景尤其有用。例如，对于 `std::vector<std::pair<int, std::string>>`，你可以使用 `vec.emplace(vec.begin(), 10, "example")`，这会直接在向量的开始位置构造一个 `std::pair` 对象。

// 2. **性能**：
//     - `emplace` 通常比 `insert` 更高效，因为它避免了不必要的临时对象创建和销毁。特别是在复杂对象的情况下，这种性能差异会更加明显。

// 3. **参数传递**：
//     - `insert` 需要一个完整的对象作为参数。
//     - `emplace` 允许传递构造函数的参数，并在容器内部直接调用构造函数，从而构造出对象。

// 下面是一个具体的代码示例，展示了 `insert` 和 `emplace` 的使用方式：

#include <iostream>
#include <vector>
#include <string>

class MyClass {
public:
    MyClass(int a, const std::string& b) : a(a), b(b) {
        std::cout << "MyClass constructed with a = " << a << " and b = " << b << "\n";
    }
    MyClass(const MyClass& other) : a(other.a), b(other.b) {
        std::cout << "MyClass copy-constructed\n";
    }
    ~MyClass() {
        std::cout << "MyClass destructed\n";
    }
private:
    int a;
    std::string b;
};

int main() {
    std::vector<MyClass> vec;

    // 使用 insert
    MyClass obj(1, "insert");
    vec.insert(vec.begin(), obj);

    // 使用 emplace
    vec.emplace(vec.begin(), 2, "emplace");

    return 0;
}

// 输出将显示 `MyClass` 对象的构造和复制情况，从而说明 `insert` 和 `emplace` 的不同之处：

// ```
// MyClass constructed with a = 1 and b = insert
// MyClass copy-constructed
// MyClass constructed with a = 2 and b = emplace
// ```

// 从输出可以看出，`insert` 首先构造一个对象，然后调用拷贝构造函数将其插入到容器中。而 `emplace` 直接在容器中构造对象，避免了额外的拷贝构造。