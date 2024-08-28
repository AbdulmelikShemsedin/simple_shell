#include "header.h"

/**
* signal_handler - handles SIGINT signal (Ctrl+C)
* @sig_num: signal number
*/
void signal_handler(int sig_num)
{
if (sig_num == SIGINT)
{
print_string("\n#shell$ ");
}
}

/**
* handle_eof - handles End of File (EOF)
* @len: return value of getline function
* @buffer: buffer
*/
void handle_eof(int len, char *buffer)
{
(void)buffer;
if (len == -1)
{
if (isatty(STDIN_FILENO))
{
print_string("\n");
free(buffer);
}
exit(0);
}
}

/**
* check_terminal - checks if the shell is running in a terminal
*/
void check_terminal(void)
{
if (isatty(STDIN_FILENO))
print_string("#shell$ ");
}
