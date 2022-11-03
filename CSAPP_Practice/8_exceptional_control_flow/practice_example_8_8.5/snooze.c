#include <stdio.h>
#include <unistd.h>

unsigned int snooze(unsigned int secs)
{
    unsigned int flag = sleep(secs);
    if (flag == 0)
        return flag;
    else
        return secs - flag;
}

int main()
{
    printf("%u", snooze(5));
    return 0;
}