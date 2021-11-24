#include "pipe.h"

void _pipe(char *arr[], int pos)
{
    int cnt = 0;
    for (int i = 0; arr[i] !=NULL; i++)
    {
        cnt++;
    }
    // printf("")
    arr[pos] = NULL;
    char  *arr1[64];
    int j = 0;
    for (int i = pos+1; i <= cnt ; i++)
    {
        arr1[j] = arr[i];
        j++;
    }
    int fd[2];
    if (pipe(fd) == -1)
    {
        return;
    }

    int pid1 = fork();
    if (pid1 < 0)
    {
        return;
    }

    if (pid1 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        // printf()
        run_command(arr);
        exit(0);
    }
    int pid2 = fork();
    if (pid2 < 0)
    {
        return;
    }

    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        run_command(arr1);
        exit(0);
    }
    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
