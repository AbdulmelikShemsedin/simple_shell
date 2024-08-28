#include "shelldata.h"
#include "function.h"
/**
 * signatureHandler - This function will handle SIGINT
 *
 * @num: a parameter that is not used
 *
 * Return: do nothing ((fflush flushes out content of output string))
 **/
void signatureHandler(int num)
{
	(void) num;

	signal(SIGINT, signatureHandler);
	display("\n$ ");
	fflush(stdout);
}
