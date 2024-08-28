#include "function.h"
#include "shelldata.h"
/**
 * writeCharacterToFD - This function will help me write
 * to a charcater to a specific file descriptor
 *
 * @cha: Character to print
 * @fil_d: specifiy file descriptor to be 0 1 or 2
 *
 * Return: On success 1.
 **/
int writeCharacterToFD(char cha, int fil_d)
{
	return (write(fil_d, &cha, 1));
}
