#include "function.h"
#include "shelldata.h"
/**
 * display - Print a message to the standard output
 *
 * @message: Message to print to the stdout
 *
 * Return: No of byte printed
 *
 **/
int display(char *message)
{
	return (outputToFD(message, 1));
}
