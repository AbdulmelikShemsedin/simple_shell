#include "function.h"
#include "shelldata.h"
/**
 * isExecutable - This function checks if a file is
 * executable by using stat function with its filename
 *
 * @name: The name of the file to check for
 *
 * Return: On success return 1 to say it has the permission
 * On error -1 is returned showing it has no permission
 **/
int isExecutable(char *name)
{
	struct stat stats;

	if (stat(name, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}

	return (-10);
}
