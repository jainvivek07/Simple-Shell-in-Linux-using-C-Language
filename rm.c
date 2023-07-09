#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void rm(int argc, char *argv[])
{
    int file;
    if (argc < 2)
    {
        printf("invalid use of command");
        return;
    }

    else if (argc > 2 && strcmp(argv[1], "-v") == 0)
    {
        for (int i = 2; i < argc; i++)
        {
            file = remove(argv[i]);
            if (file == 0)
            {
                printf("removed %s\n", argv[i]);
            }
            else
            {
                perror(argv[i]);
            }
        }
        return;
    }

    else if (argc > 2 && strcmp(argv[1], "-d") == 0)
    {
        int del = 0;
        for (int i = 2; i < argc; i++)
        {
            del = rmdir(argv[i]);
            if (del != 0)
            {
                printf("unable to delete directory %s", argv[i]);
            }
        }
        return;
    }

    else
    {
        for (int i = 1; i < argc; i++)
        {
            file = remove(argv[i]);
            if (file == 0)
            {
                printf("");
            }
            else
            {
                perror(argv[i]);
            }
        }
        return;
    }
}
