#include "main.h"

/**
 * execute_command - Execute command
 * @input: Input string containing the command and arguments
 */
void execute_command(char *input)
{
    char **tokens = malloc(sizeof(char *) * 1024);
    char *token;
    int i = 0;
    pid_t pidc;
    int status;

    if (tokens == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \n");
    while (token != NULL && i < 1023)
    {
        tokens[i++] = token;
        token = strtok(NULL, " \n");
    }
    tokens[i] = NULL; // Null-terminate the array

    pidc = fork();
    if (pidc == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pidc == 0)
    {
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);
    }

    free(tokens);
}

/**
 * main - Main function of the shell
 * Return: 0 on success, 2 on exit
 */
int main(void)
{
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t chars_read;

    while (1)
    {
        if (isatty(0) == 1)
            printf("$ ");
        chars_read = getline(&input, &bufsize, stdin);
        if (chars_read == -1)
        {
            printf("\n");
            break;
        }
        execute_command(input);
        if (strcmp(input, "exit\n") == 0)
            break;
    }

    free(input);
    return (0);
}

