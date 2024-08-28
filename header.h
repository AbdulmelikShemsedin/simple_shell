#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int write_character(char c);
void print_string(char *str);
int string_length(char *s);
char *duplicate_string(char *str);
char *concatenate_strings(char *name, char *sep, char *value);
char **split_string(char *str, const char *delim);
void execute_command(char **argv);
void *resize_memory(void *ptr, unsigned int old_size, unsigned int new_size);
void free_arguments(char **args);

extern char **environ;

/**
* struct path_list - Linked list containing PATH directories
* @dir: directory in path
* @next: pointer to next node
*/
typedef struct path_list
{
char *dir;
struct path_list *next;
} path_list;

char *get_environment_variable(const char *name);
path_list *add_node_to_end(path_list **head, char *str);
path_list *create_path_list(char *path);
char *find_command_path(char *filename, path_list *head);
void free_path_list(path_list *head);

/**
* struct builtin_command - structure for builtin commands
* @name: built-in command
* @func: function to execute the built-in command
*/
typedef struct builtin_command
{
char *name;
void (*func)(char **);
} builtin_command;

void (*find_builtin_command(char **args))(char **args);
int string_to_integer(char *s);
void exit_shell(char **args);
void print_environment(char **args);
void set_environment_variable(char **args);
void unset_environment_variable(char **args);

void signal_handler(int sig_num);
void handle_eof(int len, char *buffer);
void check_terminal(void);
ssize_t prompt_user(char **buff, size_t *size);
void handle_command(char *buff);

#endif
