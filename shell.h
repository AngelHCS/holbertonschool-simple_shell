#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"

#endif /* SHELL_H */
#include "shell.h"

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;

	while (1)
	{
		printf("($) ");
		read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (read_bytes == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		if (read_bytes == 0)
		{
			printf("\n");
			break; // End of file (Ctrl+D)
				}
		buffer[read_bytes - 1] = '\0';
		char **args = get_command(buffer);

		if (fork() == 0)
		{
			execvp(args[0], args);
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
		free(args);
	}
	return 0;
}
