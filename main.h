#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT "$ "

int cmd_token(char *s, size_t __attribute__((unused)) file_stream, char *name);
char *find_command_in_path(const char *cmd);
void cmd_err(char *cmd, char *name);
int cmd_call(char *cmd_arr[], char *name);
int _str_n_cmp(char *s1, char *s2, int n);
extern char **environ;
int _printenv(void);
char *_getenv(char *var);
int exe_cmd(char *cmd_arr[], char *name);

#endif /* MAIN_H */
