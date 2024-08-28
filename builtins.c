#include "function.h"
#include "shelldata.h"
/**
 * systemFunction - This function will help me
 * check for exec.... builtins
 *
 * @mytype: a struct with a datatype of info
 * about the shell
 * @args: the command
 *
 * Return: 1 for buitin command 0 if not
 **/
int systemFunction(shelldata_t *mytype, char **args)
{
	int update;

	update = verifyBuiltin(mytype, args);
	if (update == 0)
	{
		return (0);
	}

	return (1);
}
