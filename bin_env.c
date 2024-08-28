#include "shelldata.h"
#include "function.h"
/**
 * binaryEnv - This function helps me to implement
 * the builtin of the env
 *
 * @mytype: a struct about the shell or data created
 * @args: Command passed to the shell
 *
 * Return: nothing
 **/
void binaryEnv(shelldata_t *mytype, char **args)
{
	(void) mytype;
	(void) args;

	fetchFullEnv();
}
