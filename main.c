#include "main.h"

int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();  // Function to read input from stdin
        args = parse_line(line);  // Function to parse the input into arguments
        status = execute(args);  // Function to execute the parsed arguments

        free(line);
        free(args);
    } while (status);

    return 0;
}

