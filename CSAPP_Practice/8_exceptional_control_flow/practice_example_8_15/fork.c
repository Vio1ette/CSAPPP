#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void unix_error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}


pid_t Fork(void)
{
    pid_t pid;
    if((pid=fork())<0)
    unix_error("Fork error");
    return pid;
}

int main()
{
    pid_t pid;
    int x =1;
    printf("ok!!\n");

    pid=Fork();
    if(pid==0){ // Child
        printf("child: x=%d\n",++x);
        exit(0);
    }

    // Parent
    printf("parent: x=%d\n", --x);
    exit(0);
}