#include "function.h"
#include "shelldata.h"
/**
 * stringify - Converts a given number to a string
 *
 * @numbe: Number to convert will go here
 *
 * Return: Number which is digits will now be string
 * and will be returned as string...
 **/
char *stringify(int numbe)
{
	char *num;
	int total_digits, j;

	total_digits = number(numbe);
	num = malloc(total_digits * sizeof(char) + 1);
	if (num == NULL)
		return (NULL);
	if (numbe == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}

	num[total_digits] = '\0';

	for (j = total_digits - 1; numbe != 0; numbe /= 10, j--)
	{
		num[j] = (numbe % 10) + '0';
	}

	return (num);
}
