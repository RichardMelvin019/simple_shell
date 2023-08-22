#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void cmd_exe(char *argv[]);
char *path(char *command);
void _strcpy(char *destination, char *source);
size_t _strlen(const char *s);
void _strcat(char *destination, const char *source);
char *_strdup(char *source);

#endif
