#include "main.h"

/**
 * main - its the shell
 * Return: it works
 */

#define MAX_TOKENS 64
#define MAX_INPUT_LENGTH 1024

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *tokens[MAX_TOKENS];
	struct stat;
	char *token;
	int token_count;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		token = strtok(input, " \n");
		token_count = 0;

		while (token != NULL && token_count < MAX_TOKENS - 1)
		{
			tokens[token_count++] = token;
			token = strtok(NULL, " \n");
		}
		tokens[token_count] = NULL;

		if (token_count > 0)
			execute_command(tokens);
	}
	return (0);
}

/**
 * execute_command - Execute command
 * @tokens: Array of command-line arguments
 */
void execute_command(char **tokens)
{
	int status;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		waitpid(pid, &status, 0);
	}
}
