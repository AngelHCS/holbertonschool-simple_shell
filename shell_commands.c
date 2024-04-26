#include "main.h"

/**
 * cmd_token - handles command line and tokenizes it
 *@s: string
 *@file_stream: getline input
 *@name: name of the command
 * Return: 0
 */

int cmd_token(char *s, size_t __attribute__((unused)) file_stream, char *name)
{
	char *cmd_arr[100];
	char *token;
	int i = 0;

	if (s == NULL)
	return (0);

	if (strcmp(s, "exit") == 0)
	return (2);

	if (strcmp(s, "env") == 0)
	return (_printenv());

	token = strtok(s, " ");

	while (token != NULL && i < 100)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_arr[i] = NULL;
	if (i == 0)
		return (0);

	return (cmd_call(cmd_arr, name));
}

/**
 * cmd_err - prints a command that wasn't found
 *
 * @cmd: string from stdin
 * @name: command name
 */

void cmd_err(char *cmd, char *name)
{
        if (strcmp(_getenv("PATH"), "") == 0)
        {
                fprintf(stderr, "%s: %s: not found\n", name, cmd);
        }
        else
        {
                fprintf(stderr, "%s: %s: command not found\n", name, cmd);
        }
}

/**
 * cmd_call - calls a command, manages errors
 *
 * @cmd_arr: a string provided by the stdin
 * @name: name of the command
 * Return: 0
 */

int cmd_call(char *cmd_arr[], char *name)
{
	char *cmd = cmd_arr[0];
	struct stat buf;
	char *exe_path_str = NULL;
	int result;

	if (cmd[0] == '/' || strncmp(cmd, "./", 2) == 0 ||
		strcmp(_getenv("PATH"), "") == 0)
	{
		if (stat(cmd, &buf) == 0)
		{
			result = exe_cmd(cmd_arr, name);
			return (result);
		}
		else
		{
			cmd_err(cmd, name);
			return (3);
		}
	}

	exe_path_str = find_command_in_path(cmd);

	if (exe_path_str == NULL)
	{
		cmd_err(cmd, name);
		return (3);
	}

	cmd_arr[0] = exe_path_str;
	result = exe_cmd(cmd_arr, name);
	free(exe_path_str);
	return (result);
}

/**
 * exe_cmd - executes the command
 *
 * @cmd_arr: a string provided by the stdin
 * @name: name of the command
 * Return: 0
 */

int exe_cmd(char *cmd_arr[], char *name)
{
	pid_t pidc;
	int status;

	pidc = fork();
	if (pidc < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (pidc > 0)
	{
		wait(&status);
	}
	else if (pidc == 0)
	{
		execve(cmd_arr[0], cmd_arr, environ);
		{
			perror(name);
			exit(1);
		}
	}
	return (0);
}
