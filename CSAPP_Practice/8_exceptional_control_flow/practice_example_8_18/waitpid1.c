#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 2

void unix_error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}


pid_t Fork(void)
{
    pid_t pid;
    if ((pid = fork()) < 0) unix_error("Fork error");
    return pid;
}

int main()
{
    int   status, i;
    pid_t pid;

    // Parent creates N children
    for (i = 0; i < N; i++)
        if ((pid = Fork()) == 0) exit(100 + i);

    // Parent reaps N children in no particular order
    while ((pid = waitpid(-1, &status, 0)) > 0)
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));
        else
            printf("child %d teminated abnormally\n", pid);

    if (errno != ECHILD) unix_error("waitpid error");
    exit(0);
}