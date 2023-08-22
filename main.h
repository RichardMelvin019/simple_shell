#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>

/**
 * struct format_spec - Format Specifiers
 * @symbol: symbol to format
 * @func_ptr: function pointer
 */

typedef struct format_spec
{
	char symbol;
	void (*func_ptr)(va_list args, int *count);
} fmt_spec;

int _printf(const char *format, ...);
int _putchar(char c);
int _format(const char *format, int *count,
fmt_spec symbol_matrix[], va_list args);
int format_check(char symbol, fmt_spec symbol_matrix[],
va_list args, int *count);
void _char(va_list args, int *count);
void _string(va_list args, int *count);
void _dec(va_list args, int *count);
void _int(va_list args, int *count);


int cmd_exe(char **argv, char **env, char *lineptr,
char *lineptr_new, char *filename, char *command, int loop_count);
int get_path(char **cmd_location, char **argv, char *lineptr_new, char *lineptr);
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
int get_path_error(char *filename, char **argv, char *lineptr_new, char *lineptr, int loop_count);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *env_name, char **env);


#endif
