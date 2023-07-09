#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int ls1(int argc, const char *argv[])
{
    if (argc == 1)
    {
        struct dirent *d;
        DIR *dh = opendir(".");
        if (!dh)
        {
            if (errno == ENOENT)
            {
                perror("Directory doesn't exist!");
            }
            else
            {
                perror("Unable to read directory");
            }
        }

        while ((d = readdir(dh)) != NULL)
        {
            if (d->d_name[0] == '.')
            {
                continue;
            }
            printf("%s ", d->d_name);
        }
        printf("\n");
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-m") == 0)
        {
            struct dirent *d;
            DIR *dh = opendir(".");
            if (!dh)
            {
                if (errno == ENOENT)
                {
                    perror("Directory doesn't exist!");
                }
                else
                {
                    perror("Unable to read directory");
                }
            }

            while ((d = readdir(dh)) != NULL)
            {
                if (d->d_name[0] == '.')
                {
                    continue;
                }
                printf("%s, ", d->d_name);
            }
            printf("\n");
        }

        if (strcmp(argv[1], "-1") == 0)
        {
            struct dirent *d;
            DIR *dh = opendir(".");
            if (!dh)
            {
                if (errno == ENOENT)
                {
                    perror("Directory doesn't exist!");
                }
                else
                {
                    perror("Unable to read directory");
                }
            }

            while ((d = readdir(dh)) != NULL)
            {
                if (d->d_name[0] == '.')
                {
                    continue;
                }
                printf("%s\n", d->d_name);
            }
            printf("\n");
        }
    }
    return 0;
}
