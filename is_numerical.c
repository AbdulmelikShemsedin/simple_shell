#include "function.h"
#include "shelldata.h"
/**
 * isNumeric - Check if a given parameter is a digit
 *
 * @number: Number needed to check
 *
 * Return: 1 if it is a number and return 0 if not
 *
 */
int isNumeric(unsigned int number)
{
	return (number >= '0' && number <= '9');
}
