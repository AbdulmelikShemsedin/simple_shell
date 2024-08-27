#include "main.h"

/**
 * main - simple shell
 * @argc: arg count
 * @argv: arg vector
 * @envp: ...
 * Return: EXIT_SUCCESS if succeed
 */

int main(int argc __attribute__((unused)),
	char **argv __attribute__((unused)), char **envp)
{
char *line;
char **args;
int status;

do {
write(STDOUT_FILENO, "$ ", 2);
line = read_line();
args = split_line(line);
status = execute(args, envp);

free(line);
free(args);
} while (status);
return (EXIT_SUCCESS);
}
