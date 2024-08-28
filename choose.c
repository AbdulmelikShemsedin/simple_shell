#include "function.h"
#include "shelldata.h"
/**
 * choose - This function is built to find directories
 * when it's needed...
 *
 * @dirname: directory name inputed
 * @mytype: A struct that defines a certain data type...
 *
 * Return: pointer to a string
 * given the path to the directory
 */
char *choose(char *dirname, shelldata_t *mytype)
{
	char *path, *path_temp, *tok, *del;
	int space;

	(void) mytype;

	path = getEnv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	tok = strtok(path, ":");

	space = _strlen(dirname) + 2;
	del = malloc(space * sizeof(char));
	del = _strcpy(del, "/");
	del = _strcat(del, dirname);

	while (tok != NULL)
	{
		path_temp = malloc(_strlen(tok) + space);
		path_temp = _strcpy(path_temp, tok);
		path_temp = _strcat(path_temp, del);

		if (isExecutable(path_temp) == 1)
		{
			free(path);
			free(del);
			return (path_temp);
		}
		tok = strtok(NULL, ":");

		free(path_temp);
	}

	free(del);
	free(path);

	return (NULL);
}
