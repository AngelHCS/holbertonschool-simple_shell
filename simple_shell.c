#include "main.h"

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

/**
 * display_prompt - Display shell prompt
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

/**
 * read_command - Read command from user
 * @command: Buffer to store the command
 * @size: Size of the buffer
 * Return: Number of characters read
 */

ssize_t read_command(char *command, size_t size)
{
	return (getline(&command, &size, stdin));
}

/**
 * execute_command - Execute command
 * @command: Command to execute
 */

void execute_command(char *command)
{
	char *args[MAX_ARGUMENTS];
	int i = 0;
	char *token;
	pid_t pid;

	token = strtok(command, " \n");
	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *command_path = "/bin/";

		strcat(command_path, args[0]);

		execve(command_path, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Main function of the shell
 * Return: Always 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	ssize_t chars_read;

	while (1)
	{
		display_prompt();
		chars_read = read_command(command, sizeof(command));

		if (chars_read == -1)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) > 0)
		{
			execute_command(command);
		}
	}

	return (0);
}
