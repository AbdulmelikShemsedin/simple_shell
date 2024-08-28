#include "function.h"
#include "shelldata.h"
/**
 * manageNumbers - This function will help
 * Control the argument of exit builtin
 *
 * @mytype: a pointer to a struct to access its types
 * @argument: Argument of the builtin exit passed
 *
 * Return: If the actual argument exist then return 1
 * else return 0 which is negative
 **/
int manageNumbers(shelldata_t *mytype, char *argument)
{
	int tracker;

	tracker = _atoi(argument);

	if (tracker < 0 || hasLetter(argument))
	{
		mytype->code_stat = 2;
		mytype->error_digit = 133;
		additionalError(mytype, argument);
		return (0);
	}

	if (tracker > 255)
	{
		mytype->code_stat = tracker % 256;
	}
	else
	{
		mytype->code_stat = tracker;
	}

	return (1);
}
