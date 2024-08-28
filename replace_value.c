#include "function.h"
#include "shelldata.h"
/**
 * subtituteValue - Function that helps with replacing a pattern value
 *
 * @mytype: a struct param called info
 * @id: takes care of position
 * @str: string input
 *
 * Return: a pointer to a bunch of character called string
**/
char *subtituteValue(shelldata_t *mytype, int *id, char *str)
{
	char *param;
	int j, old_str, new_str;

	j = *id;
	j++;

	param = exchange(mytype, id, str + j);
	if (param == NULL)
	{
		str = _strcpy(str, "");

		return (str);
		;
	}

	old_str = _strlen(str);
	new_str = _strlen(param) + 1;
	str = _realloc(str, old_str, new_str);
	str = _strcpy(str, param);

	releaseMemory(param);
	*id = j;

	return (str);
}
