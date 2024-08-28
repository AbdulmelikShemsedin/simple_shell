#include "function.h"
#include "shelldata.h"
/**
 * fetchFullEnv - This function will help get all
 * the environment variable
 *
 * Return: nothing, just get the env. variable and carry on
 *
 **/
void fetchFullEnv(void)
{
	int j = 0;
	char **temp;

	for (j = 0, temp = environ; temp[j] != NULL; j++)
	{
		display(temp[j]);
		writeCharacter('\n');
	}
}
