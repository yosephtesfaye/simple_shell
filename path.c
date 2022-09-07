#include "shell.h"
/**
 * find_path - finds path
 * @filename: file name
 * @tmp: saves the PATH string
 * @er: an error message
 * Return: Success - path/filename, failure - er
 */
char *find_path(char *filename, char *tmp, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *file_path, *path, *ret;

	int len = 0;

	while (filename[len])
		len++;
	path = _getenv("PATH");

	tmp = save_path(tmp, path);

	file_path = strtok(tmp, ":");

	while (file_path)
	{
		dir = opendir(file_path);

		if (!dir)
		{
			printf("Error! Unable to open directory.\n");
			exit(0);
		}
		while ((sd = readdir(dir)))
		{
			ret = read_dir(er, sd, filename, len, file_path, tmp);
			if (ret != er)
			{
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
			}
		}
		closedir(dir);
		file_path = strtok(NULL, ":");
	}
	path = NULL;

	free(tmp);
	return (er);
}
