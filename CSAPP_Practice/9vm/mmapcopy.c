#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void mymap(int fd, size_t size)
{
    const void* buf = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    write(1, buf, size);  // 完成复制功能
    return;
}

int main(int argc, char** argv)
{
    if (argc < 1)
        return 0;
    // printf(stdout);

    const char* filename = argv[1];
    // FILE* f = fopen(filename, "r");
    int fd = open(filename, O_RDONLY);
    // fseek(f, 0L, SEEK_END);
    struct stat* buf;
    fstat(fd, buf);

    // int length = lseek(fd, 0, SEEK_END)+1;
    // long size = ftell(f);
    mymap(fd, buf->st_size);

    return 0;
}