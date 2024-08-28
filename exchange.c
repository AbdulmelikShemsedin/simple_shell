#include "function.h"
#include "shelldata.h"
/**
 * exchange - This function is used to replace
 *
 * @mytype: a struct called g_t that takes in a pointer
 * @id: index parameter to take note
 * @word: input words
 *
 * Return: pointer to a string
**/
char *exchange(shelldata_t *mytype, int *id, char *word)
{
	char *temp, sign;

	(void) id;

	sign = *word;
	if (sign != '?' && sign != '$')
	{
		temp = subEnv(mytype, word);
		return (temp);
	}

	temp = (sign == '$') ? stringify(mytype->pid) :
		stringify(mytype->code_stat);

	return (temp);
}
