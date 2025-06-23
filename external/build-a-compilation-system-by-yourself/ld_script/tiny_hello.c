char *str = "hello world!\n";

void print()
{
    asm(
        "mov $13,%%rdx\n\t"
        "mov %0,%%rcx\n\t"
        "mov $0,%%rbx\n\t"
        "mov $4,%%rax\n\t"
        "int $0x80\n\t" ::"r"(str) : "rdx", "rcx", "rbx");
}

void exit()
{
    asm(
        "mov $42,%rbx\n\t"
        "mov $1,%rax\n\t"
        "int $0x80\n\t");
}

void nomain()
{
    print();
    exit();
}

/*
使用asm语句、使用链接脚步

gcc -c -fno_builtin tiny_hello.c
ld -static -e nomain -o tiny_hello.out tiny_hello.o
ld -static -T ld_script.lds -o tiny_hello.2.out tiny_hello.o
readelf -S tiny_hello.out
*/
