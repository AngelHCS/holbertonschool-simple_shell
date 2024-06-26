C - Simple Shell

Table of content

Description

Allowed functions and system calls

Compilation

Testing

Output

Tasks

Authors

Description

This basic command-line interpreter can process command lines with arguments and look for executables in the directories given in the PATH environment variable. It is called a simple shell. Errors can be handled, and the "end of file" circumstance can be handled. The shell can manage straightforward command lines with only one word, but it does not support complex features like semicolons, pipes, or input/output redirection. Each time a command is run, the shell shows a prompt and ends each command line with a new line. The user can exit the shell with the built-in "exit" command, and the "env" command prints the current environment. The shell prints an error message and re-displays the prompt if an executable cannot be located.

Allowed functions and system calls

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

Compilation

Our shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Testing

Our shell should work like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

Output

Unless specified otherwise, our program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
Same error with your program hsh:

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

Tasks

0. README, man, AUTHORS

Write a README
Write a man for your shell.
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

1. Betty would be proud

Write a beautiful code that passes the Betty checks.

2. Simple shell 0.1

Write a UNIX command line interpreter.

3. Simple shell 0.2

Simple shell 0.1 +

Handle command lines with arguments.

4. Simple shell 0.3

Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist

5. Simple shell 0.4

Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

6. Simple shell 1.0

Simple shell 0.4 +

Implement the env built-in, that prints the current environment.

Authors

This project was assigned to and created by Ángel Suárez (7630@holbertonstudents.com), Thais Rodríguez (9022@holbertonschoolstudents.com) and Ángel Carrasquillo (8990@holbertonschoolstudents.com).
