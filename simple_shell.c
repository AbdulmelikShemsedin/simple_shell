#include "main.h"

void simple_shell(char *prog_name)
{
	char *line_buffer = NULL;
	size_t buffer_size = 0;
	ssize_t line_size;
	char **command_args;

	while (1)
	{
		printf("simple_shell$ ");
		line_size = getline(&line_buffer, &buffer_size, stdin);

		if (line_size == -1)
		{
			free(line_buffer);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		line_buffer[strcspn(line_buffer, "\n")] = '\0';

		if (line_buffer[0] != '\0')
		{
			command_args = tokenize_command(line_buffer);
			if (command_args[0] != NULL)
			{
			int exit_status = exe_cmd(command_args, prog_name);
				if (exit_status == 111)
				{
					fprintf(stderr, "%s: fork failed\n", prog_name);
				}
				else if (exit_status == 112)
				{
					fprintf(stderr, "%s: command not found\n", prog_name);
					release_args(command_args);
				}
			}
		}
	}
}
