#include "main.h"

/**
 * read_line - Uses the getline() function to read the user’s input
 *
 * Return: the stdin line
 */
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;  // getline() will allocate the buffer size

if (getline(&line, &bufsize, stdin) == -1) {
if (feof(stdin)) {
exit(EXIT_SUCCESS);  // Handle EOF (Ctrl+D)
} else {
perror("readline");
exit(EXIT_FAILURE);
}
}

return line;
}
