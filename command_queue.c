#include "shell.h"

char **strtok_commands(char *tmp, char *delm)
{
        unsigned int i = 0, k = 0;
        int j = 0;
        char **pholder = (char **)malloc(sizeof(char *) * 256);

        *pholder = tmp;
        for (i = 0 ; i < 256 ; i++)
        {
                pholder[i] = (char *)malloc(sizeof(char) * 256);
        }
        for (i = 0 ; i < _strlen(tmp) ; i++, j++)
        {
                if (i < _strlen(tmp) - 4)
                {
                        if (tmp[i] == ' ' && (tmp[i + 1] == '&' || tmp[i + 1] == '|') && (tmp[i + 2] == '&' || tmp[i + 2] == '|') && tmp[i + 3] == ' ')
                        {
                                delim_sorter(tmp, pholder, delm, &i, &j, &k);
                                continue;
                        }
                        if (tmp[i] == ' ' && tmp[i + 1] == ';' && tmp[i + 2] == ' ')
                        {
                                i+=2;
                                delm[k] = ';';
                                
                                k++;
                                delm[k] = '\0';
                                j = -1;
                                continue;
                        }
                        pholder[k][j] = tmp[i];
                }
                else
                        pholder[k][j] = tmp[i];
                pholder[k][j + 1] = '\0';
        }
        return (pholder);
}
void delim_sorter(char *tmp, char **pholder, char *delm, unsigned int *i, int *j, unsigned int *k)
{
        if (tmp[(*i) + 1] == '&')
        {
                (*i)+=3;
                delm[(*k)] = '&';
                delm[*(k) + 1] = '\0';
        }
        else
        {
                (*i)+=3;
                delm[(*k)] = '|';
                delm[*(k) + 1] = '\0';
        }
        pholder[(*k)][(*j)] = '\0';
        (*k)++;
        (*j) = -1;
}