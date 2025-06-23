/*
来自《程序员的自我修养————链接、装载与库》第三章：目标文件里有什么
*/

int printf(const char *format, ...);

int global_init_var = 84;
int global_unint_var;

void func1(int i)
{
    printf("%d\n", i);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;

    int a = 1;
    int b;

    func1(static_var + static_var2 + a + 1);

    return 1;
}


/*
gcc -o simple_section.o -c simple_section.c
objdump -h simple_section.o
size simple_section.o
objdump -x -s -d simple_section.o

readelf 和 objdump 指令的异同
   - **`readelf`**：主要用于查看 ELF 文件结构，具有一些特定的选项，如 `-h`（查看 ELF 头）、`-S`（查看节头）、`-l`（查看程序头）、`-s`（查看符号表）等。
   - **`objdump`**：除了可以查看 ELF 文件头和段信息外，还提供了反汇编功能，如 `-d`（反汇编所有可执行代码）、`-s`（显示各段的内容）、`-f`（显示文件格式信息）等。
*/
