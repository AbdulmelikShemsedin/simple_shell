#include "shelldata.h"
#include "function.h"
/**
 * writeCharacter - Print a character to the standard output
 *
 * @character: Character to print is pased
 *
 * Return: On success 1 which is the number of character
 *
 **/
int writeCharacter(char character)
{
	return (write(1, &character, 1));
}
