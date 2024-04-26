#include "shell.h"

char get_command(char *input)
{
	char args = malloc((BUFFER_SIZE / 2 + 1) *sizeof(char));
	if (args == NULL){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	chartoken = strktok(input, TOKEN_DELIMITER);
	while (token != NULL){
		args[i] = token;
		token = strtok(NULL, TOKEN_DELIMITER);
		i++;
	}
	args[i] = NULL;

	return args;
}
