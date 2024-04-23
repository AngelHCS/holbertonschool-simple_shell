#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


/* prototypes */

void execute_command(char *command);
void display_prompt(void);
ssize_t read_command(char *command, size_t size);

#endif
