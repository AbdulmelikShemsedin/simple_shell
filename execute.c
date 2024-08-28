#include "header.h"

/**
* split_string - splits a string and makes it an array of pointers to words
* @str: the string to be split
* @delimiter: the delimiter
* Return: array of pointers to words
*/
char **split_string(char *str, const char *delimiter)
{
int i, num_words;
char **array;
char *token;
char *copy;

copy = malloc(string_length(str) + 1);
if (copy == NULL)
{
perror(get_environment_variable("_"));
return (NULL);
}
i = 0;
while (str[i])
{
copy[i] = str[i];
i++;
}
copy[i] = '\0';

token = strtok(copy, delimiter);
array = malloc((sizeof(char *) * 2));
array[0] = duplicate_string(token);

i = 1;
num_words = 3;
while (token)
{
token = strtok(NULL, delimiter);
array = resize_memory(array, (sizeof(char *) * (num_words - 1)),
	(sizeof(char *) * num_words));
array[i] = duplicate_string(token);
i++;
num_words++;
}
free(copy);
return (array);
}

/**
* execute_command - executes a command
* @argv: array of arguments
*/
void execute_command(char **argv)
{
int pid, status;

if (!argv || !argv[0])
return;
pid = fork();
if (pid == -1)
{
perror(get_environment_variable("_"));
}
if (pid == 0)
{
execve(argv[0], argv, environ);
perror(argv[0]);
exit(EXIT_FAILURE);
}
wait(&status);
}

/**
* resize_memory - Reallocates memory block
* @ptr: previous pointer
* @old_size: old size of previous pointer
* @new_size: new size for our pointer
* Return: New resized Pointer
*/
void *resize_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new;
char *old;

unsigned int i;

if (ptr == NULL)
return (malloc(new_size));

if (new_size == old_size)
return (ptr);

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new = malloc(new_size);
old = ptr;
if (new == NULL)
return (NULL);

if (new_size > old_size)
{
for (i = 0; i < old_size; i++)
new[i] = old[i];
free(ptr);
for (i = old_size; i < new_size; i++)
new[i] = '\0';
}
if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
new[i] = old[i];
free(ptr);
}
return (new);
}

/**
* free_arguments - frees the array of pointers args
* @args: array of pointers
*/
void free_arguments(char **args)
{
int i;

for (i = 0; args[i]; i++)
free(args[i]);
free(args);
}
