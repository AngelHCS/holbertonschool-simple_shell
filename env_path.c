#include "main.h"

/**
 * getpath - Reads the PATH and tokenizes it
 * @cmd: command passed from getline in main
 * Return: new_path for use in cmd_read
 */

char *getpath(char *cmd)
{
	char *path = strdup(_getenv("PATH"));
	int i = 0, j = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = cmd;
	char *new_path = NULL;
	struct stat buf;

	new_path = malloc(sizeof(char) * 1000);
	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (strdup(cmd));

	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;

	for (j = 0; path_array[j]; j++)
	{
		strcpy(new_path, path_array[j]);
		strcat(new_path, "/");
		strcat(new_path, s2);

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}

		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);
	if (stat(cmd, &buf) == 0)
		return (strdup(cmd));
	return (NULL);
}

/**
 * _printenv - prints environment like printenv
 *
 * Return: 0
 */

int _printenv(void)
{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, strlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}

/**
 * _strncmp - compares two strings and returns an integer.
 * @s1: first string
 * @s2: second string
 * @n: Represents the count of the comparison
 * Return: Value depending on string used
 */

int _strncmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)

			return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
	}
	return (0);
}

/**
 * _getenv - Workaround to use getenv function.
 * @var: Is the value of the variable
 * Return: the value of the variable
 */

char *_getenv(char *var)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], var, strlen(var)) == 0)
			return (&environ[i][strlen(var)]);
	}
	return (NULL);
}
