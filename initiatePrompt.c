#include "function.h"
#include "shelldata.h"
/**
 * initiatePrompt - This function represents the main loop of the
 * interactive prompt
 *
 * @mytype: Struct of general information
 *
 * Return: Buffer gotten from stdin or NULL if EOF was found
 **/
void initiatePrompt(shelldata_t *mytype)
{
	char *buffer, **args, *env_path;

	signal(SIGINT, signatureHandler);
	while (1)
	{
		getInput(mytype);

		env_path = getEnv("PATH");
		isCurrPath(env_path, mytype);

		mytype->env = env_path;
		buffer = parse_prompt();
		if (buffer == NULL)
		{
			display(mytype->it_mode == 1 ? "exit\n" : "");
			free(env_path);
			break;
		}
		mytype->n_cmd++;
		if (buffer[0] != '\n')
		{
			args = tokenize_words(buffer, " \t\n");

			mytype->thearguments = args;
			mytype->buf = buffer;
			patternAnalysis(mytype, args);
			evaluate(args, mytype, buffer);

			releaseMemoryPointer((void *) args);
		}
		releaseMemory((void *) buffer);
		releaseMemory((void *) env_path);
	}

}
