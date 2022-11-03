#include "csapp.h"


void sigint_handler(int sig) {
    printf("\n");
    return;
}

unsigned int snooze(unsigned int secs)
{
    unsigned int flag = sleep(secs);
    printf("Slept for %d of %d secs.", secs-flag, secs);
}

int main(int argc, char** argv)
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR) 
        unix_error("signal error");
    unsigned int secs = (unsigned int)atoi(argv[1]);
    unsigned int temp = snooze(secs);

    exit(0);
}