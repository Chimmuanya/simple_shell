#ifndef _CSHELL_H_
#define _CSHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


void cmdexec(char **argv);
char *locate_cmd(char *str);

/*locate_cmd.c*/
void start_child(char **argv, char **env);

/*error_prints.c*/
int print_dec(int input, int fd);
void print_err(char *fname, char *err_str);
int pstr_tofd(char *str, int fd);
int pchar_tofd(char c, int fd);
void _putserr(char *str);
int _puterr(char c);


/*print.c*/
void _puts(char *str);
int _putchar(char c);

/*signal.c*/
void sigintHandler(__attribute__((unused))int sig_num);


#endif
