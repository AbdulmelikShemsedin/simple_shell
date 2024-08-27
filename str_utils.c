#include "main.h"

/**
 * _strcmp - custom strcmp
 * @s1: str 1
 * @s2: str 2
 * Return: the strcmp of s1 & s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strlen - custom strlen
 * @s: the str
 * Return: the length
 */
int _strlen(char *s)
{
int len = 0;

while (*s++)
{
len++;
}
return (len);
}
