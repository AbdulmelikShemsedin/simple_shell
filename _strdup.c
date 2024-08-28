#include "function.h"
#include "shelldata.h"
/**
 * _strdup - A function that copies a string
 *
 *
 * @str: String to copy is passed
 *
 * Return: A character pointer to the newly allocated string
 * in memory
 **/
char *_strdup(char *str)
{
	char *dest;
	int str_size, j;

	if (str == NULL)
	{
		return (NULL);
	}

	str_size = _strlen(str) + 1;
	dest = malloc(str_size * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < str_size; j++)
	{
		dest[j] = str[j];
	}

	return (dest);
}
