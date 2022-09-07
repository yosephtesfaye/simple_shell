#include "shell.h"
/**
 * parser - parse the argument
 * @buf: the input text
 * @buf_cpy: copy of buf
 */

void parser(char *buf, char *buf_cpy)
{
	char *token;

	int num_tok = 0, i;

	char delim[] = " \n";

	char **argv = NULL;

	token = strtok(buf, delim);

	while (token)
	{
		num_tok++;

		token = strtok(NULL, delim);
	}
	num_tok++;

	argv = malloc(sizeof(char *) * num_tok);

	token = strtok(buf_cpy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));

		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	launch_prog(argv);

	free(argv);
	free(token);
}
