#include "main.h"

int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("#shell: ");
        line = read_line();
        args = parse_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);

    return 0;
}

