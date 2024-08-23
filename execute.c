#include "main.h"

int exe_cmd(char **command_args, char *shell_name)
{
	pid_t child_pid;
	int status;
	char *path_var = getenv("PATH");
	char *full_command_path = NULL;
	char **path_directories;
	int index;
	(void)shell_name;

	if (command_args[0] == NULL)
	{
		return 0;
	}

	if (strcmp(command_args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(command_args[0], "env") == 0)
	{
		display_env();
		return 0;
	}
	path_directories = split_path_var(path_var);
	for (index = 0; path_directories[index] != NULL; index++)
	{
		full_command_path = create_full_path(path_directories[index], command_args[0]);
		if (access(full_command_path, X_OK) == 0)
		{
			break;
		}
		free(full_command_path);
		full_command_path = NULL;
	}

	if (full_command_path == NULL)
	{
		free(path_directories);
		return 112;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		free(full_command_path);
		free(path_directories);
		return 101;
	}
	else if (child_pid == 0)
	{
		execv(full_command_path, command_args);
		exit(102);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(full_command_path);
		free(path_directories);
		return 0;
	}
}
