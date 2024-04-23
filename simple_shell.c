#include "main.h"

/**
 * main - its the shell
 * Return: Success
 */

int main(void)
{
	pid_t pidc;
	char *token, *b = NULL;
	size_t bufsize = 32;
	char **av;
	int status;
	struct stat sb;

	while (1)
	{
		if (isatty(0) == 1)
			printf("$ ");
		if (getline(&b, &bufsize, stdin) == -1)
		{
			printf("\n");
			break;
		}
		token = strtok(b, " \n");
		av = malloc(1024);
		av[0] = token;
		token = strtok(NULL, " \n");
		av[1] = token;
		token = strtok(NULL, " \n");
		av[2] = token;
		pidc = fork();
		wait(&status);
		if (pidc == 0)
		{
			if (stat(av[0], &sb) == 0)
			{
				execve(av[0], av, NULL);
			}
			else
				break;
		}
		free(av);
		if (pidc == -1)
		{
			printf("Error de forkeo\n");
		}
		if (_strcmp(b, "exit") == 0)
		{
			free(b);
			return (2);
		}
	}
	free(av);
	free(b);
	return (0);
}
