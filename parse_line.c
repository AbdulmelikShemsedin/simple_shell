#include "main.h"

/**
 * parse_line - Use the strtok() function to split the input string into arguments
 * @line: the input str
 * Return: the arguments (tokens)
 */
char **parse_line(char *line)
{
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char*));
char *token;

if (!tokens) {
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, TOK_DELIM);
while (token != NULL) {
tokens[position] = token;
position++;

if (position >= bufsize) {
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char*));
if (!tokens) {
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOK_DELIM);
}
tokens[position] = NULL;
return tokens;
}
