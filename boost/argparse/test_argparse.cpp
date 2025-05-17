#include <boost/program_options.hpp>
#include <iostream>
#include <string>

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    // 定义变量来存储参数
    std::string name;
    int age = 0;
    bool help = false;

    // 定义程序选项
    po::options_description desc("可用选项");
    desc.add_options()("help,h", "显示帮助信息")(
        "name,n", po::value<std::string>(&name)->default_value("无名"),
        "提供名称")("age,a", po::value<int>(&age)->default_value(0), "提供年龄");

    // 解析命令行参数
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm); // 解析参数并更新变量

    // 显示帮助信息
    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    // 打印解析结果
    std::cout << "名称: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;

    return 0;
}