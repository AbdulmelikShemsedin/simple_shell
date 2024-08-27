#include "main.h"

/**
 * read_line - read stdin
 *
 * Return: the stdin line
 */
char *read_line(void)
{
char *line = malloc(1024);
ssize_t bytes_read;

if (!line)
{
perror("malloc");
exit(EXIT_FAILURE);
}

bytes_read = read(STDIN_FILENO, line, 1024);
if (bytes_read < 0)
{
perror("read");
exit(EXIT_FAILURE);
}

line[bytes_read - 1] = '\0';
return (line);
}

/**
 * split_line - splits the lines
 * @line: ...
 * Return: tokens
 */
char **split_line(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
int token_length;

if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = line;
while (*token != '\0')
{
while (*token == ' ' || *token == '\t')
{
token++;
}

if (*token == '\0')
{
break;
}

tokens[position] = token;
token_length = 0;

while (*token != '\0' && *token != ' ' && *token != '\t')
{
token++;
token_length++;
}

if (*token != '\0')
{
*token = '\0';
token++;
}

position++;
if (position >= bufsize)
{
perror("Too many arguments");
exit(EXIT_FAILURE);
}
}

tokens[position] = NULL;
return (tokens);
}
