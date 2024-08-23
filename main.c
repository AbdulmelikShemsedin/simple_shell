#include "main.h"

int main(int argc, char **argv)
{
	if (argc == 0 || argv[0] == NULL)
	{
		fprintf(stderr, "Error: Missing program name.\n");
		return EXIT_FAILURE;
	}

	simple_shell(argv[0]);
	return 0;
}
