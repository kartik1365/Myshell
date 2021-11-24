#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "run_command.h"

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokenize(char *line)
{
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
    int i, tokenIndex = 0, tokenNo = 0;

    for (i = 0; i < strlen(line); i++)
    {

        char readChar = line[i];

        if (readChar == ' ' || readChar == '\n' || readChar == '\t')
        {
            token[tokenIndex] = '\0';
            if (tokenIndex != 0)
            {
                tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
                strcpy(tokens[tokenNo++], token);
                tokenIndex = 0;
            }
        }
        else
        {
            token[tokenIndex++] = readChar;
        }
    }

    free(token);
    tokens[tokenNo] = NULL;
    return tokens;
}

void main(void)
{
    char line[MAX_INPUT_SIZE];
    char **tokens;
    int i;

    while (1)
    {
        printf("Hello>");
        bzero(line, MAX_INPUT_SIZE);
        gets(line);
        printf("Got command %s\n", line);
        line[strlen(line)] = '\n'; //terminate with new line
        if(line[0] == '\n')
            continue;
        char *ptr;
        char *str = strtok_r(line, ";;", &ptr);
        while (str != NULL)
        {
            // printf("%s\n", str);
            tokens = tokenize(str);
            // printf("%s\n", tokens[0]);
            run_command(str);
            str = strtok_r(NULL, ";;", &ptr);
        }
        for (i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
    }
}
