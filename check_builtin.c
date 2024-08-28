#include "function.h"
#include "shelldata.h"
/**
 * verifyBuiltin - This function helps confirm a builtin cmd
 *
 * @mytype: a struct with data type about the shell
 * @args: argument count
 *
 * Return: 1 for buitin and 0 if not
 **/
int verifyBuiltin(shelldata_t *mytype, char **args)
{
	int j, space;

	sysFunction_t builtins[] = {
		{"exit", binaryExit},
		{"env", binaryEnv}
	};

	space = sizeof(builtins) / sizeof(builtins[0]);
	j = 0;
	while (j < space)
	{
		if (_strcmp(mytype->cmd, builtins[j].cmd) == 0)
		{
			builtins[j].func(mytype, args);
			return (1);
		}
		j++;
	}

	return (0);
}
