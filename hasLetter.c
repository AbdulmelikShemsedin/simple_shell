#include "function.h"
#include "shelldata.h"
/**
 * hasLetter - search if a digit string contains letter
 *
 * @string: String to check for presence of letter
 *
 * Return: If a non-digits was found, return 1
 * if not, return 0
 **/
int hasLetter(char *string)
{
	int j;

	for (j = 0; string[j] != '\0'; j++)
	{
		if (isNumeric(string[j]) == 0)
			return (1);
	}

	return (0);
}
