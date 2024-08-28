#include "function.h"
#include "shelldata.h"
/**
 * evaluate - run analysis on args passed to the prompt
 *
 * @args: argument to check for
 * @mytype: a struct created of a certain data type
 * @buffer: Line accepted/read storage
 *
 * Return: nothing, just do the task
 **/
void evaluate(char **args, shelldata_t *mytype, char *buffer)
{
	char *cmd;
	int update;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	cmd = args[0];
	mytype->cmd = cmd;
	if (verifyBuiltin(mytype, args) == 1)
	{
		return;
	}
	update = isFile(cmd);
	if (update == 0)
	{
		mytype->code_stat = 126;
		mytype->error_digit = 13;
		issue(mytype);
		return;
	}
	if (update == 1)
	{
		run(cmd, args, mytype, buffer);
		return;
	}
	if (getCurrentDir(cmd, args, buffer, mytype) == 1)
		return;
	mytype->cmd_path = choose(cmd, mytype);
	if (mytype->cmd_path != NULL)
	{
		run(mytype->cmd_path, args, mytype, buffer);
		releaseMemory((void *) mytype->cmd_path);
		return;
	}
	mytype->code_stat = 127;
	mytype->error_digit = 132;
	issue(mytype);
}
