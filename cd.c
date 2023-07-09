#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cd(int argc, char *args)
{
    if (argc < 1)
    {
        printf("invalid arguments\n");
        return;
    }
    if (argc == 1)
    {
        chdir(getenv("HOME"));
        return;
    }
    else if (argc == 2)
    {
        if (chdir(args) == 0)
        {
            return;
        }
        else if (strcmp(args, "~") == 0)
        {
            chdir(getenv("HOME"));
            return;
        }

        else if (chdir(args) != 0)
        {
            printf("can't change the directory to %s\n", args);
            return;
        }
    }
    else
    {
        printf("Invalid use of cd command!\n");
        return;
    }
}
