#include "function.h"
#include "shelldata.h"
/**
 * isFile - This function checks if a paticular name
 * is a file or binary
 *
 * @filename: File to check if it has the permission to
 * execute
 *
 * Return: If is a file with the right permission
 * it will
 **/
int isFile(char *filename)
{
	int j, aye;

	aye = _strlen(filename);
	for (j = 0; j < aye; j++)
		if (filename[j] == '/')
		{
			return (isExecutable(filename));
		}

	return (-10);
}
