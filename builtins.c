#include "header.h"

/**
* exit_shell - exits the shell with or without a return of status n
* @args: array of arguments
*/
void exit_shell(char **args)
{
int i, status;

if (args[1])
{
status = string_to_integer(args[1]);
if (status <= -1)
status = 2;
free_arguments(args);
exit(status);
}
for (i = 0; args[i]; i++)
free(args[i]);
free(args);
exit(0);
}

/**
* string_to_integer - converts a string into an integer
* @s: pointer to a string
* Return: the integer
*/
int string_to_integer(char *s)
{
int i, integer, sign = 1;

i = 0;
integer = 0;
while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
{
if (s[i] == '-')
{
sign = sign * (-1);
}
i++;
}
while ((s[i] >= '0') && (s[i] <= '9'))
{
integer = (integer * 10) + (sign * (s[i] - '0'));
i++;
}
return (integer);
}

/**
* print_environment - prints the current environment
* @args: array of arguments
*/
void print_environment(char **args __attribute__ ((unused)))
{
int i;

for (i = 0; environ[i]; i++)
{
print_string(environ[i]);
print_string("\n");
}
}

/**
* set_environment_variable - Initialize a new environment variable
* @args: array of entered arguments
*/
void set_environment_variable(char **args)
{
int i, j, k;

if (!args[1] || !args[2])
{
perror(get_environment_variable("_"));
return;
}

for (i = 0; environ[i]; i++)
{
j = 0;
if (args[1][j] == environ[i][j])
{
while (args[1][j])
{
if (args[1][j] != environ[i][j])
break;

j++;
}
if (args[1][j] == '\0')
{
k = 0;
while (args[2][k])
{
environ[i][j + 1 + k] = args[2][k];
k++;
}
environ[i][j + 1 + k] = '\0';
return;
}
}
}
if (!environ[i])
{
environ[i] = concatenate_strings(args[1], "=", args[2]);
environ[i + 1] = '\0';
}
}

/**
* unset_environment_variable - Remove an environment variable
* @args: array of entered arguments
*/
void unset_environment_variable(char **args)
{
int i, j;

if (!args[1])
{
perror(get_environment_variable("_"));
return;
}
for (i = 0; environ[i]; i++)
{
j = 0;
if (args[1][j] == environ[i][j])
{
while (args[1][j])
{
if (args[1][j] != environ[i][j])
break;

j++;
}
if (args[1][j] == '\0')
{
free(environ[i]);
environ[i] = environ[i + 1];
while (environ[i])
{
environ[i] = environ[i + 1];
i++;
}
return;
}
}
}
}
