#include "main.h"

/**
 * shell_exit - the exit command
 * @args: ...
 * Return: 0 if succeed
 */
int shell_exit(char **args __attribute__((unused)))
{
return (0);
}

/**
 * shell_env - the env command
 * @args: ...
 * Return: 1 if succeed
 */
int shell_env(char **args __attribute__((unused)))
{
extern char **environ;
char **env = environ;

while (*env)
{
write(STDOUT_FILENO, *env, _strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}

return (1);
}
