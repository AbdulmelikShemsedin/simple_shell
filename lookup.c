#include "header.h"

/**
* find_builtin_command - checks if the command is a built-in
* @args: array of arguments
* Return: pointer to function that takes args and returns void
*/
void (*find_builtin_command(char **args))(char **args)
{
int i, j;
builtin_command commands[] = {
{"exit", exit_shell},
{"env", print_environment},
{"setenv", set_environment_variable},
{"unsetenv", unset_environment_variable},
{NULL, NULL}
};

for (i = 0; commands[i].name; i++)
{
j = 0;
if (commands[i].name[j] == args[0][j])
{
for (j = 0; args[0][j]; j++)
{
if (commands[i].name[j] != args[0][j])
break;
}
if (!args[0][j])
return (commands[i].func);
}
}
return (0);
}
