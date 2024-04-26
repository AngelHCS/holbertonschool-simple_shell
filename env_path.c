#include "main.h"

/**
 * find_command_in_path - Reads the PATH and tokenizes it
 * @cmd: command passed from getline in main
 * Return: new_path for use in cmd_read
 */

char *find_command_in_path(const char *cmd) {
    char *path = getenv("PATH");
    char *path_token;
    char *path_array[100];
    char *new_path;
    struct stat buf;
    int i = 0, j;

    if (!path || *path == '\0') {
        fprintf(stderr, "PATH environment variable is empty.\n");
        return NULL;
    }

    path_token = strtok(path, ":");
    while (path_token != NULL && i < 99) {
        path_array[i++] = path_token;
        path_token = strtok(NULL, ":");
    }
    path_array[i] = NULL;

    new_path = (char *)malloc(strlen(cmd) + 1);
    if (!new_path) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    for (j = 0; path_array[j] != NULL; j++) {
        strcpy(new_path, path_array[j]);
        strcat(new_path, "/");
        strcat(new_path, cmd);

        if (stat(new_path, &buf) == 0 && S_ISREG(buf.st_mode)) {
            return new_path;
        }
    }

    free(new_path);
    return NULL;
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
