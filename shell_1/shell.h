#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void putstring(char *string);
void _getcmd(char **argv);
char *_strdup(char *str);
char *_strcpy(char *src, char *dest);

#endif /* SHELL_H */
