#include "header.h"

/**
* get_environment_variable - gets the value of the global variable
* @name: name of the global variable
* Return: string of value
*/
char *get_environment_variable(const char *name)
{
int i, j;
char *value;

if (!name)
return (NULL);
for (i = 0; environ[i]; i++)
{
j = 0;
if (name[j] == environ[i][j])
{
while (name[j])
{
if (name[j] != environ[i][j])
break;

j++;
}
if (name[j] == '\0')
{
value = (environ[i] + j + 1);
return (value);
}
}
}
return (0);
}

/**
* add_node_to_end - adds a new node at the end of a path_list
* @head: pointer to pointer to our linked list
* @str: directory path to add
* Return: address of the new element/node
*/
path_list *add_node_to_end(path_list **head, char *str)
{
path_list *temp;
path_list *new_node;

new_node = malloc(sizeof(path_list));

if (!new_node || !str)
return (NULL);

new_node->dir = duplicate_string(str);
new_node->next = NULL;
if (!*head)
{
*head = new_node;
}
else
{
temp = *head;
while (temp->next)
{
temp = temp->next;
}
temp->next = new_node;
}

return (*head);
}

/**
* create_path_list - creates a linked list for PATH directories
* @path: string of path value
* Return: pointer to the created linked list
*/
path_list *create_path_list(char *path)
{
path_list *head = NULL;
char *token;
char *copied_path = duplicate_string(path);

token = strtok(copied_path, ":");
while (token)
{
add_node_to_end(&head, token);
token = strtok(NULL, ":");
}

free(copied_path);
return (head);
}

/**
* find_command_path - finds the full pathname of a file in PATH directories
* @filename: name of file or command
* @head: head of linked list of path directories
* Return: pathname of filename or NULL if no match
*/
char *find_command_path(char *filename, path_list *head)
{
struct stat st;
char *path;

path_list *temp = head;

while (temp)
{
path = concatenate_strings(temp->dir, "/", filename);
if (stat(path, &st) == 0)
{
return (path);
}
free(path);
temp = temp->next;
}

return (NULL);
}

/**
* free_path_list - frees a path_list
* @head: pointer to our linked list
*/
void free_path_list(path_list *head)
{
path_list *temp;

while (head)
{
temp = head->next;
free(head->dir);
free(head);
head = temp;
}
}
