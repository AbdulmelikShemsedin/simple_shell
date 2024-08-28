#include "function.h"
#include "shelldata.h"
/**
 * run - This function helps to execute
 * a command in other process called child
 *
 * @cmd: Command to execute is received here
 * @argu: Arguments passed to the command is also received here
 * @mytype: a struct of the type info
 * @buffer: Line readed or created
 *
 * Return: nothing... just perform the task and continue
 **/
void run(char *cmd, char **argu, shelldata_t *mytype, char *buffer)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, argu, environ);
		perror("./sh");

		releaseMemoryPointer((void *) argu);

		if (mytype->cmd_path != NULL)
		{
			free(mytype->cmd_path);
			mytype->cmd_path = NULL;
		}

		free(mytype);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			mytype->code_stat = WEXITSTATUS(status);
		}
	}
}
