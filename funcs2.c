#include "main.h"

/**
 * lsh_cd - for cd case
 * @args: inputs
 * Return: 1 in success
 */

int lsh_cd(char **args)
{
if (args[1] == NULL) {
	fprintf(stderr, "lsh: expected argument to \"cd\"\n");
} else {
	if (chdir(args[1]) != 0) {
		perror("lsh");
	}
}
return 1;
}

/**
 * lsh_help - help cases
 * @args: inputs
 * Return: 1 if succeed
 */

int lsh_help(char **args)
{
int i;
BuiltinCommands commands = init_builtins(); // Re-initialize to access built-ins

printf("Simple Shell\n");
printf("Type program names and arguments, and hit enter.\n");
printf("The following are built in:\n");

for (i = 0; i < commands.num_builtins; i++) {
printf("  %s\n", commands.builtin_str[i]);
}

return (1);
}

/**
 * lsh_exit - exit cases
 * @args: inputs
 * Return: 0 exit
 */

int lsh_exit(char **args)
{
return 0;
}
