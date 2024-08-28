#include "header.h"

/**
* prompt_user - Displays prompt and handles EOF
* @buff: buffer for input
* @size: size of the buffer
* Return: length of input or -1 if EOF
*/
ssize_t prompt_user(char **buff, size_t *size)
{
_isatty();
return (getline(buff, size, stdin));
}

/**
* handle_command - Processes and executes user commands
* @buff: input buffer
*/
void handle_command(char *buff)
{
char **args;
char *path_value, *cmd_path;
path_list *path_list_head = NULL;
void (*builtin_func)(char **);

args = split_string(buff, " \n");
if (!args || !args[0])
{
execute_command(args);
return;
}

path_value = get_environment_variable("PATH");
path_list_head = create_path_list(path_value);
cmd_path = find_command_path(args[0], path_list_head);
builtin_func = find_builtin_command(args);

if (builtin_func)
{
free(buff);
builtin_func(args);
}
else
{
if (cmd_path)
{
free(args[0]);
args[0] = cmd_path;
}
execute_command(args);
}

free_path_list(path_list_head);
free_arguments(args);
}

/**
* main - Entry point for the shell
* Return: 0 on success
*/
int main(void)
{
ssize_t len;
char *buff = NULL;
size_t size = 0;

signal(SIGINT, signal_handler);

while ((len = prompt_user(&buff, &size)) != -1)
{
handle_command(buff);
}

handle_eof(len, buff);
return (0);
}
