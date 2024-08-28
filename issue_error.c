#include "function.h"
#include "shelldata.h"
/**
 * issue - This function will help handle error
 * and print the error encountered
 *
 * @mytype: a struct called info that declares
 * several types for the shell
 *
 * Return: it will return nothing... it will do the
 * task and print the error and continue with the prog..
 **/
void issue(shelldata_t *mytype)
{
	char *msg, *num, *au;
	int num_size, msg_size;

	num = NULL;
	msg = selectMessage(*mytype);
	num = stringify(mytype->n_cmd);

	num_size = _strlen(num);
	msg_size = _strlen(mytype->argv[0]);

	au = malloc(msg_size + num_size + 3);

	au = _strcpy(au, mytype->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, num);

	msg = mergeWords(au, mytype->cmd, msg, ": ");
	displayError(msg);

	free(msg);
	free(num);
	free(au);
}
