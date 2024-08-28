#include "function.h"
#include "shelldata.h"
/**
 * displayError - The function helps to print to the
 * standard error (2)
 *
 * @message: Message to print is passed here
 *
 * Return: Number of bytes printed by the function
 **/
int displayError(char *message)
{
	return (outputToFD(message, 2));
}
