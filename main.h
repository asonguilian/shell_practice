#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/*===== linked list definition for a directory======*/
struct path_list
{
	char *dir;
	struct path_list *next;
};
typedef struct path_list path_list;

/*=======functions in string_utils.c=========*/
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_memcpy(char *dest, const char *src, unsigned int n);
char *_strdup(const char *str);

/*=====functions in _which_gui.c========*/
char *_which(const char *cmd);

/*=====functions in env_task2_6_gui.c=========*/

int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *name);
void print_path_dir();
path_list *get_path_list();
void print_path_list(path_list *head);


#endif
