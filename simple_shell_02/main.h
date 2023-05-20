#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>


/***======linked list definition for directories===*/
/**
  * struct path_list - definiton of a linked list for directories
  * @dir: directory name
  * @next: pointer to the next node in the list
  */
struct path_list
{
	char *dir;
	struct path_list *next;
};
typedef struct path_list path_list;


/***======functions in string_utils_gui.c========***/
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_memcpy(char *dest, const char *src, unsigned int n);
char *_strdup(const char *str);

/***======functions in string_utils2_gui.c=========***/
char *_strchr(const char *s, int c);
int _strncmp(const char *s1, const char *s2, size_t n);

/***======functions in set_env_gui.c==========*****/
int is_valid_name(const char *name);
char *create_env_string(const char *name, const char *value);
int _set_env_replace(const char *name, const char *value);
int _set_env_add(const char *name, const char *value);
int _setenv(const char *name, const char *value, int overwrite);
/***=====functions in env_task2_6gui.c=======***/
char *_getenv(const char *name);
void print_path_dir(void);
path_list *get_path_list(void);
void print_path_list(path_list *head);

/***======functions in memory.c========*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
