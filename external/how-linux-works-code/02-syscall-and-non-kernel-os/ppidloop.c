/*系统调用，由汇编语言发起

Breakpoint 1, main () at ppidloop.c:7
7                       getppid();
(gdb) s
__GI_getppid () at ../sysdeps/unix/syscall-template.S:91
91      ../sysdeps/unix/syscall-template.S: No such file or directory.
(gdb) disassemble
Dump of assembler code for function __GI_getppid:
=> 0x00007ffff7eae430 <+0>:     mov    $0x6e,%eax
   0x00007ffff7eae435 <+5>:     syscall
   0x00007ffff7eae437 <+7>:     ret
End of assembler dump.
*/

#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    for (;;)
        getppid();
}
