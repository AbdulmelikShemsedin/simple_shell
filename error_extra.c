#include "function.h"
#include "shelldata.h"
/**
 * additionalError - This function Prints the error
 * message with extra/more information about the error
 *
 * @mytype: a struct that gives info about the shell
 * also decleares a type for this info
 * @more: The Extra information or more info about the error
 * message
 *
 * Return: nothing.... just print error and continue...
 **/
void additionalError(shelldata_t *mytype, char *more)
{
	char *msg, *num;
	char *au, *au2;
	int num_size, msg_size;
	int more_size;

	num = NULL;
	msg = selectMessage(*mytype);
	num = stringify(mytype->n_cmd);

	num_size = _strlen(num);
	msg_size = _strlen(mytype->argv[0]);
	more_size = _strlen(more);

	au = malloc(msg_size + num_size + 3);
	au = _strcpy(au, mytype->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, num);

	au2 = malloc(_strlen(msg) + more_size + 3);
	au2 = _strcpy(au2, msg);
	au2 = _strcat(au2, ": ");
	au2 = _strcat(au2, more);

	msg = mergeWords(au, mytype->cmd, au2, ": ");
	displayError(msg);

	free(msg);
	free(num);
	free(au);
	free(au2);
}
