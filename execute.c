#include "main.h"

/**
 * execute - Use fork(), execvp(), and waitpid() to execute commands
 * @args: commands
 * Return: 1 in success
 */
int execute(char **args)
{
pid_t pid/*, wpid*/;
/*int status;*/

if (args[0] == NULL) {
return 1;
}

pid = fork();
if (pid == 0) {
if (execvp(args[0], args) == -1) {
perror("lsh");
}
exit(EXIT_FAILURE);
} else if (pid < 0) {
perror("lsh");
} else {
/*do {
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));*/
}

return 1;
}
