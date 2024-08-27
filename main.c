#include "main.h"

/**
 * main - simple shell
 *
 * Return: EXIT_SUCCESS if succeed
 */

int main(void)
{
char *line;
char **args;
int status;

do {
write(STDOUT_FILENO, "$ ", 2);
line = read_line();
args = split_line(line);
status = execute(args);

free(line);
free(args);
} while (status);
return (EXIT_SUCCESS);
}
