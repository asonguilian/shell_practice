#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void putstring(char *string);
int _getcmd(char **cmd);
char *_strdup(char *str);
char *_strcpy(char *src, char *dest);
void exec(char *prompt, char *file);
int _strlen(char *str);

#endif /* SHELL_H */
