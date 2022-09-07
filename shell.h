#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void read_cmd(void);
void parser(char *buf, char *buf_cpy);
void exec_cmd(char **args);
int launch_prog(char **args);

#endif
