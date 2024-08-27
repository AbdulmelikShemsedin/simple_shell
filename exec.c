#include "main.h"

/**
 * execute - commands execution
 * @args: ...
 * @envp: ...
 * Return: the return of launched
 */
int execute(char **args, char **envp)
{
if (args[0] == NULL)
{
return (1);
}

if (_strcmp(args[0], "exit") == 0)
{
return (shell_exit(args));
}
if (_strcmp(args[0], "env") == 0)
{
return (shell_env(args, envp));
}

return (launch(args));
}

/**
 * launch - for non built in commands
 * @args: ...
 * Return: 1 if succeed
 */
int launch(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("execve");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("fork");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}
