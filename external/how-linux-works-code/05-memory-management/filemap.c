#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1000
#define ALLOC_SIZE (100 * 1024 * 1024)

static char command[BUFFER_SIZE];
static char file_contents[BUFFER_SIZE];
static char overwrite_data[] = "HELLO";

int main(void)
{
    pid_t pid;

    pid = getpid();
    snprintf(command, BUFFER_SIZE, "cat /proc/%d/maps", pid);

    puts("*** memory map before mapping file ***");
    fflush(stdout);
    system(command);

    int fd;
    fd = open("testfile", O_RDWR);
    if (fd == -1)
        err(EXIT_FAILURE, "open() failed");

    char *file_contents;
    file_contents = mmap(NULL, ALLOC_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_contents == (void *)-1)
    {
        warn("mmap() failed");
        goto close_file;
    }

    puts("");
    printf("*** succeeded to map file: address = %p; size = 0x%x ***\n", file_contents, ALLOC_SIZE);

    puts("");
    puts("*** memory map after mapping file ***");
    fflush(stdout);
    system(command);

    puts("");
    printf("*** file contents before overwrite mapped region: %s", file_contents);

    // 覆写映射区域
    memcpy(file_contents, overwrite_data, strlen(overwrite_data));

    puts("");
    printf("*** overwritten mapped region with: %s\n", file_contents);

    if (munmap(file_contents, ALLOC_SIZE) == -1)
        warn("munmap() failed");
close_file:
    if (close(fd) == -1)
        warn("close() failed");
    exit(EXIT_SUCCESS);
}
