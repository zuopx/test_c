#include <iostream>
#include <string>

int main() {
    std::string str1 = "3.14159";
    std::string str2 = "42.0 more text";  // 包含额外文本的字符串
    size_t idx;

    try {
        double value1 = std::stod(str1);  // 正常转换
        std::cout << "Converted value: " << value1 << std::endl;

        double value2 = std::stod(str2, &idx);  // 转换部分字符串
        std::cout << "Converted value: " << value2 << std::endl;
        std::cout << "Remaining text starts at index: " << idx << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0;
}
