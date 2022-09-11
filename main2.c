#include "shell.h"

/**
 * INThandler - handles signals and write the prompt
 *@sig: signal to handle
 *Return: Nothing (void)
 */

void INThandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * print_dollar - Function to print the dollar sign
 *Return: Nothing(void)
 */

void print_dollar(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * main - principal function to run the shell
 *@argc: argument count
 *@argv: argument vector
 *@env: enviroment variables
 *Return: 0 on exit, 1 if any failures happen
 */

int main(int argc, char **argv, char **env)
{
	/*Added two pointers comarray and delm*/
	char *buffer, **commands, *delm, **comarray, *comarray_copy = malloc(sizeof(char) * 256);
	size_t length;
	ssize_t characters;
	pid_t pid;
	int status, count;
    unsigned int i;

	(void)argc;
	buffer = NULL, length = 0, count = 0;
	/*write promt only if it's from standard input*/
	print_dollar();
	/*infinite loop*/
    delm = malloc(sizeof(char) * 256);
	while ((characters = getline(&buffer, &length, stdin)))
	{
		/*signal kill for control + c */
		signal(SIGINT, INThandler);
		/*check the end of file*/
		if (characters == EOF)
			end_file(buffer);
		count++;

		buffer[_strlen(buffer) - 1] = '\0';/*replace the new line by null*/
		/* Comarray is a double array which is used to hold 
        commands separated by ; , && or ||.delm is an array 
        which holds the delimiters.During each loop the 
        delimiter is checked and together with status will be 
        used to determine if the next command should be 
        executed.*/
        
        /* strtok_commands sections buffer using 
        delimiters ; , && and ||*/
		delm[0] = '\0';
		comarray = strtok_commands(buffer, delm);
		for (i = 0 ; i <= _strlen(delm); i++)
		{
			/* In delm array & = 0, || = 1 and ; = 2
			printf("%u Delm:%c Status:%d\n", _strlen(delm), delm[i], WIFEXITED(status));*/
			if (i == 0 || (i > 0 && ((delm[i - 1] == '&' && WIFEXITED(status) == 1) || (delm[i - 1] == '|' && WIFEXITED(status) == 0) || delm[i - 1] == ';')))
			{
				/*collect commands from the prompt and store in double pointer*/
                _strcpy(comarray_copy, comarray[i]);
                commands = array_strtok(comarray_copy);
				/*create new process*/
				pid = fork();
				if (pid == -1)
					fork_fail();
				if (pid == 0) 
					execute(commands, comarray[i], env, argv, count);
				/*free everithing*/
				else
				{
					wait(&status);
				}
            }
        }
                length = 0, buffer = NULL; /*reset for getline*/
				send_to_free(buffer, commands);
                print_dollar();
	}
	return ((characters == -1) ? EXIT_FAILURE : EXIT_SUCCESS);
}