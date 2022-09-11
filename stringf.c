#include "shell.h"

char *_strcat(char *s1, char *s2)
{
	unsigned int i, len = _strlen(s1) + _strlen(s2);
	char *s3 = NULL;/* = malloc(sizeof(char) * len);*/
	for (i = 0 ; i < len ; i++)
	{
		if (i < _strlen(s1))
			s3[i] = *(s1 + i);
		else
			s3[i] = *(s2 + i - _strlen(s1));
	}
	return (s3);
}
void _strcpy(char *s1, char *s2)
{
	while (*s2) 
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = *s2;
	/*
	int i = 0;
	printf("s1:%s s2:%s\n", s1, s2);
	if (_strlen(s1) >= _strlen(s2))
	{
		while (s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	printf("s1:%s s2:%s\n", s1, s2);
	*/
}
char *binarywpath(char *s1, char *s2)
{
	unsigned int i, len;
	char *s3 = malloc(sizeof(char) * 128);
	
	len = _strlen(s1) + _strlen(s2);
	for (i = 0 ; i <= len ; i++)
	{
		if (i < _strlen(s1))
			s3[i] = *(s1 + i);
		else if (i == _strlen(s1))
			s3[i] = '/';
		else
			s3[i] = *(s2 + i - _strlen(s1) - 1);
	}
	s3[i] = '\0';
	printf("Conact: %s\n", s3);
	return (s3);
}
char *_strtok(char *s1, char *delim)
{
	unsigned int i;
	char *tmp = NULL;

	for (i = 0 ; i < _strlen(s1) - 1 ; i++)
	{
		if (!_strcmp(s1 + i, delim))
			tmp[i] = *(s1 + i);
		else 
			break;
	}
	return (tmp);
	/*
	printf("%u\n", (unsigned int)strlen(tmp[0]));
	for (i = strt ; i < strlen(tmp[0]) - 1 ; i++)
	{
		if (_strcmp(tmp[0][i], delm))
		{
			for (j = 0 ; _strcmp(tmp[0][i], 58) ; j++,i++)
				pholder[k][j] = tmp[0][i];
			k++;
		}
	}
	printf("%s\n", *pholder);
	*/
}
/*
int main()
{
	unsigned int i;
	char *s1 = "The first string";
	char *s2 = "The second string";

	i = _strlen(s1);
	printf("%uLength of first string:u\n", i);
	i = _strlen(s2);
	printf("%uLength of first string:u\n", i);
	printf("%d\n", _strcmp(s1, s2));
	printf("%d\n", _strcmp(s1, s2));
	printf("%s\n", _strcat(s1, s2));
	return (0);
}
*/
