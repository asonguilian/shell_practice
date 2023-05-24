#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>


/*which.c*/
char *_which(char *cmd, char **environ);

/*env_functions.c*/
char *_getenv(char *name, char **environ);

/*string_functions1.c*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *str);

/*string_functions2.c*/
char *_strchr(char *s, int c);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);
int _isinteger(char *str);
int _atoi(char *s);

/*cmd_functions.c*/
int read_cmd(char **command);
int parse_cmd(char *command, char **args);
int execute_cmd(char ***args, char *file_name, char **env);

/*print_functions.c*/
void print_msg(char *msg);
void print_env(char **env);

/*exit.c*/
void exit_shell(int status);

/*builtin.c*/
int handle_builtin(char **args, char **env, int num_args);


/*main.c*/
void handle_interactive_mode(char *prompt, char **env, char *file_name);
void handle_non_interactive_mode(char **env, char *filename);
int main(int ac, char *argv[], char **env);



#endif
