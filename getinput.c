#include "function.h"
#include "shelldata.h"
/**
 * getInput - This function serves as the prompt
 * for the simple shell program
 *
 * @mytype: Struct of general information which
 * has been defined in an header file
 **/
void getInput(shelldata_t *mytype)
{
	if (mytype->it_mode == 0)
	{
		return;
	}

	display("$ ");
}
