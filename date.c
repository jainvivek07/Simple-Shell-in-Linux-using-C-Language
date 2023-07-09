#include <stdio.h>
#include <time.h>
#include <string.h>

void date(int x, char *args[])
{
    if (x < 1 || x > 2)
    {
        printf("invalid use of command");
        return;
    }

    else if (x == 1)
    {
        time_t dateandtime;
        time(&dateandtime);
        printf("%s", ctime(&dateandtime));
        return;
    }

    else if (x == 2 && strcmp(args[1], "-d") == 0)
    {
        time_t t;
        t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        return;
    }

    else if (x == 2 && strcmp(args[1], "-t") == 0)
    {
        time_t ti;
        ti = time(NULL);
        struct tm tme;
        tme = *localtime(&ti);
        printf("%d:%d:%d\n", tme.tm_hour, tme.tm_min, tme.tm_sec);
        return 0;
    }
}
