#include "function.h"
#include "shelldata.h"
/**
 * number - Count the number of digits a given number has
 *
 * @num: The given number
 *
 * Return: The digit of the number counted
 **/
int number(int num)
{
	int j = 0;

	while (num != 0)
	{
		j++;
		num = num / 10;
	}

	return (j);
}
