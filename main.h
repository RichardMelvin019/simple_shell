#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int cmd_exe(char **argv, char **env, char *lineptr,
char *lineptr_new, char *filename, char *command);
char *path(char *command);
void _strcpy(char *destination, char *source);
size_t _strlen(const char *s);
void _strcat(char *destination, const char *source);
char *_strdup(char *source);
int check_getline(char *lineptr, size_t buff_size);
int get_line(char **env, char *filename);
int process_line(char *lineptr, char **argv, char **env, char *filename);
int check_white_space(const char *lineptr);
int tokenize_line(char *lineptr, char *lineptr_new, char ***argv);
int _isspace(int digit);
int memory_free(char *lineptr, char *lineptr_new, char **argv);

#endif
