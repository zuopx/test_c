/*将数学库模块用运行时加载的方法加载到进程中，然后获取sin()函数的符号地址，并进行调用

gcc -o test_dlopen.out test_dlopen.c -ldl
./test_dlopen.out /usr/lib/x86_64-linux-gnu/libm.so.6

如何找到数学库路径：
    find /usr/lib -name "libm.*"
    find /usr/lib -name "libm.*" -exec file {} \;
*/

#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *handle;
    double (*func)(double);
    char *error;

    handle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL)
    {
        printf("Open library %s error: %s\n", argv[1], dlerror());
        return -1;
    }

    func = dlsym(handle, "sin");
    if ((error = dlerror()) != NULL)
    {
        printf("Symbol sin not found: %s\n", error);
    }
    else
    {
        printf("%f\n", func(3.1415926 / 2));
    }

    dlclose(handle);
}
