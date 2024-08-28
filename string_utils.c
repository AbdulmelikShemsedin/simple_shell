#include "header.h"

/**
* duplicate_string - returns a pointer to a newly allocated space in memory
* contains a copy of the string given as a parameter
* @str: pointer to a string
* Return: pointer to a new string
*/
char *duplicate_string(char *str)
{
int i, len;
char *new_str;

if (!str)
{
return (NULL);
}
len = string_length(str);
new_str = malloc(sizeof(char) * (len + 1));
if (!new_str)
{
return (NULL);
}
for (i = 0; i < len; i++)
{
new_str[i] = str[i];
}
new_str[len] = '\0';
return (new_str);
}

/**
* concatenate_strings - concatenates 3 strings into a new allocated memory
* @str1: first string
* @separator: separator string
* @str2: third string
* Return: pointer to the new string
*/
char *concatenate_strings(char *str1, char *separator, char *str2)
{
char *result;
int len1, len2, len3, i, j;

len1 = string_length(str1);
len2 = string_length(separator);
len3 = string_length(str2);

result = malloc(len1 + len2 + len3 + 1);
if (!result)
return (NULL);

for (i = 0; str1[i]; i++)
result[i] = str1[i];
j = i;

for (i = 0; separator[i]; i++)
result[j + i] = separator[i];
j = j + i;

for (i = 0; str2[i]; i++)
result[j + i] = str2[i];
j = j + i;

result[j] = '\0';

return (result);
}

/**
* string_length - returns the length of a string
* @s: pointer to the string
* Return: the length of the string
*/
int string_length(char *s)
{
int i = 0;

while (s[i] != '\0')
{
i++;
}
return (i);
}

/**
* write_character - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int write_character(char c)
{
return (write(1, &c, 1));
}

/**
* print_string - prints a string
* @str: pointer to string
*/
void print_string(char *str)
{
int i = 0;

while (str[i])
{
write_character(str[i]);
i++;
}
}
