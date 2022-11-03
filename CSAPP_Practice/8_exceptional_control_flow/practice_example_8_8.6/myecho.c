#include <stdio.h>

int main(int argc, char** argv, char** envp)
{
    printf("Command-ine arguments:\n");
    for (int i = 0; i < argc; i++) { printf("       argv[%d]: %s\n", i, argv[i]); }

    printf("Environment variables:\n");

    int t = 0;
    while (envp[t] != NULL) { printf("       envp[%d]: %s\n", t, envp[t++]); }
}