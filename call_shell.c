#include "main.h"

/**
 * main - Is the shell, works like a basic shell.
 * @argc: arg count (not needed)
 * @argv: argv for command
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *s = NULL;
	size_t buffer_size = 0;
	ssize_t file_stream = 0;
	char *name = argv[0];

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 3);
		file_stream = getline(&s, &buffer_size, stdin);
		if (file_stream == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		if (s[file_stream - 1] == '\n')
			s[file_stream - 1] = '\0';
		if (*s == '\0')
			continue;
		if (cmd_token(s, file_stream, name) == 2)
		{
			free(s);
			exit(EXIT_SUCCESS);
		}
	}
	free(s);
	s = NULL;
	return (0);
}
