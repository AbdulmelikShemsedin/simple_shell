#include "function.h"
#include "shelldata.h"
/**
 * mergeWords - Join 3 words with a delimitar / spearator
 *
 * @w1: Word1 to join
 * @w2: Word2 to join
 * @w3: Word3 to join
 * @del: Separator between the words
 *
 * Return: a string composed of strings joined together
 **/
char *mergeWords(char *w1, char *w2, char *w3, const char *del)
{
	int size1, size2, size3, del_size;
	char *joint;

	size1 = size2 = size3 = del_size = 0;

	if (w2 != NULL)
		size2 = _strlen(w2);
	else
		w2 = "";

	if (w1 != NULL)
		size1 = _strlen(w1);
	else
		w1 = "";
	if (w3 != NULL)
		size3 = _strlen(w3);
	else
		w3 = "";
	if (del != NULL)
		del_size = _strlen((char *)del);
	else
		del = "";

	joint = malloc(size1 + del_size + size2 + del_size + size3 + 2);
	if (joint == NULL)
	{
		return (NULL);
	}
	joint = _strcpy(joint, w1);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w2);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w3);
	joint = _strcat(joint, "\n");

	return (joint);
}
