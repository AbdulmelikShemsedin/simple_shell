#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void simple_shell(char *prog_name);
int exe_cmd(char **command_args, char *shell_name);
char **tokenize_command(char *line_buffer);
void release_args(char **args);
void display_env(void);
char **split_path_var(char *path_var);
char *create_full_path(char *directory, char *command);


#endif
