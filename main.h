#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int launch(char **args);
int shell_exit(char **args);
int shell_env(char **args);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void *_memset(void *s, int c, size_t n);

#endif
