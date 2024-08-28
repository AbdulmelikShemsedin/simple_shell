#include "function.h"
#include "shelldata.h"
/**
 * tokenize_words - Split a string into words based on a delimeter
 *
 * @string: string to separate
 * @del: Delimiter to use to separate thestring
 *
 * Return: string pointer to the splited words
 **/
char **tokenize_words(char *string, const char *del)
{
	unsigned int old, new;
	char **word, **temp, *token;

	old = sizeof(char *);
	word = malloc(old);
	if (word != NULL)
	{
		new = 1;
		token = strtok(string, del);
		while (token)
		{
			if (token[0] == '#')
				break;
			temp = _realloc(word, old, (new + 1) * sizeof(char *));
			old = (new + 1) * sizeof(char *);
			if (temp == NULL)
				break;
			word = temp;
			++new;

			word[new - 2] = malloc(_strlen(token) + 1);
			if (word == NULL)
			{
				free(word);
				free(temp);
			}

			if (word[new - 2] != NULL)
			{
				_strcpy(word[new - 2], token);
			}
			token = strtok(NULL, del);
			temp = NULL;
		}
		word[new - 1] = NULL;
	}
	return (word);
}
