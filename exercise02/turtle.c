#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "run_command.h"
#include "tokenize.h"

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void signal_handler(int signal_number)
{
    // Write your code here.
    if (signal_number == 2)
    {
        printf("\nInterrupt received\n");
        printf("Hello>");
        fflush(0);
        return;
    }
}

int main(void)
{
    signal(SIGINT, signal_handler);
    char line[MAX_INPUT_SIZE];
    char **tokens;

    while (1)
    {
        printf("Hello>");
        bzero(line, MAX_INPUT_SIZE);
        gets(line);
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '"')
            {
                line[i] = ' ';
            }
        }
        // printf("Got command %s\n", line);
        if (line[strlen(line) - 1] == ';')
        {
            line[strlen(line) - 1] = ' ';
            line[strlen(line) - 2] = ' ';
        }
        line[strlen(line)] = '\n'; //terminate with new line
        if (line[0] == '\n')
            continue;

        char *ptr;
        char *str = strtok_r(line, ";;", &ptr);
        while (str != NULL)
        {
            // printf("%s\n", str);
            tokens = tokenize(str);
            // for (int i = 0; tokens[i] != NULL; i++)
            //     printf("tkn-%s\n", tokens[i]);
            run_command(tokens);
            str = strtok_r(NULL, ";;", &ptr);
        }
        for (int i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
    }
}
