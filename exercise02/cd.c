#include "cd.h"
void cd(char *arr[])
{
    int cnt = 0;
    for (int i = 1; arr[i] != NULL; i++)
    {
        cnt++;
    }
    if (cnt >= 2)
    {
        printf("No such directory exists\n");
        return;
    }
    // printf
    int out = chdir(arr[1]);
    if (out == -1)
    {
        printf("No such directory exists\n");
        return;
    }
}