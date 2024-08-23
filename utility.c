#include "main.h"

char **tokenize_command(char *line_buffer)
{
	char **args_array = NULL;
	char *token;
	int array_size = 10;
	int idx = 0;

	args_array = malloc(array_size * sizeof(char *));
	if (args_array == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line_buffer, " ");
	while (token != NULL)
	{
		if (idx >= array_size)
			{
				array_size *= 2;
				args_array = realloc(args_array, array_size * sizeof(char *));
				if (args_array == NULL)
				{
					perror("realloc");
					exit(EXIT_FAILURE);
				}
			}
		args_array[idx++] = token;
		token = strtok(NULL, " ");
	}
	args_array[idx] = NULL;
	return args_array;
}

void release_args(char **args_array)
{
	free(args_array);
}

void display_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

char **split_path_var(char *path_var)
{
	char **directories = NULL;
	char *token;
	int size = 10;
	int idx = 0;

	directories = malloc(size * sizeof(char *));
	if (directories == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(path_var, ":");
	while (token != NULL)
	{
		if (idx >= size)
		{
			size *= 2;
			directories = realloc(directories, size * sizeof(char *));
			if (directories == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		directories[idx++] = token;
		token = strtok(NULL, ":");
	}
	directories[idx] = NULL;
	return directories;
}

char *create_full_path(char *directory, char *command)
{
	char *path;
	int length;

	length = strlen(directory) + strlen(command) + 2;
	path = malloc(length);
	if (path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	snprintf(path, length, "%s/%s", directory, command);
	return path;
}
