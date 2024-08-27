#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

typedef struct {
	char **builtin_str;
	int (**builtin_func)(char **);
	int num_builtins;
} BuiltinCommands;

char *read_line(void);
char **parse_line(char *line);
int execute(char **args);
int lsh_cd(char **args);
int lsh_help();
int lsh_exit();
BuiltinCommands init_builtins();

#endif
