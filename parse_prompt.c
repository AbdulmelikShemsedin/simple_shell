#include "function.h"
#include "shelldata.h"
/**
 * parse_prompt - This function uses the getline function
 * to read the line of the prompt
 *
 * Description: it will also handle the end of file
 * triggered by pressing ctrl D
 *
 * Return: Buffer readed or NULL after freeing the read prompt if EOF
 **/
char *parse_prompt(void)
{
	char *buffer = NULL;
	int ret;
	size_t size;

	ret = getline(&buffer, &size, stdin);

	if (ret == EOF)
	{
		releaseMemory((void *) buffer);
		return (NULL);
	}

	return (buffer);
}
