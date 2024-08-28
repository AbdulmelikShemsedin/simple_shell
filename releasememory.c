#include "function.h"
#include "shelldata.h"
/**
 * releaseMemory - This function helps to free a pointer
 *
 * @pointer: Pointer to free is passed
 * Return: void, it just frees and carry on
 **/
void releaseMemory(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
	pointer = NULL;
}
