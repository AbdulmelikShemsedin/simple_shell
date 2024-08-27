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
 * @envp: ...
 * Return: 1 if succeed
 */
int shell_env(char **args __attribute__((unused)), char **envp)
{
while (*envp)
{
write(STDOUT_FILENO, *envp, _strlen(*envp));
write(STDOUT_FILENO, "\n", 1);
envp++;
}

return (1);
}
