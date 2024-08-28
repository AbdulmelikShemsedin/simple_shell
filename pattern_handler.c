#include "function.h"
#include "shelldata.h"
/**
 * handle_pattern - This function handles pattern and serves as a
 * helper function
 * @mytype: a struct parameter
 * @words: a pointer to a string passed as parametet
 * Return: a pointer to a string
**/
char *handle_pattern(shelldata_t *mytype, char *words)
{
	int j;

	for (j = 0; words[j] != '\0'; j++)
	{
		if (words[j] == '$' && words[j + 1] != '\0')
		{
			words = subtituteValue(mytype, &j, words);
		}
	}

	return (words);
}
