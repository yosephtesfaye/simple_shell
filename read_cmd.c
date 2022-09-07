#include "shell.h"
/**
 * read_cmd - accept input from the user
 */
void read_cmd(void)
{
	size_t buf_size;
	ssize_t nread;

	char *buf = NULL;

	char *buf_cpy = NULL;

	write(1, "#cisfun$", 9);
	nread = getline(&buf, &buf_size, stdin);

	if (nread == -1)
	{
		exit(0);
	}
	buf_cpy = malloc(sizeof(char) * nread);

	strcpy(buf_cpy, buf);
	parser(buf, buf_cpy);

	free(buf);
	free(buf_cpy);
}
