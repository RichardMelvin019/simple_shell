#include "main.h"

/**
 * process_line - processes line
 * @num_read: number read
 * @lineptr: lineptr
 * Return: integer
*/
int process_line(char *lineptr, char **argv, char **env, char *filename, char *command_path)
{
	char *lineptr_new = NULL;
	int count_token = 0;

	if (check_white_space(lineptr) == 1)
	{
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	lineptr_new = _strdup(lineptr);
	if (lineptr_new == NULL)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	count_token = tokenize_line(lineptr, lineptr_new, &argv);
	if (count_token > 0)
	{
		if (access(argv[0], F_OK) == 0)
			cmd_exe(argv, env, lineptr, lineptr_new, filename, argv[0]);
		else
		{
			get_path();
			cmd_exe(argv, env, lineptr, lineptr_new, filename, command_path);
		}
	}
	return (0);
}

/**
 * check_white_space - checks white space
 * @lineptr: lineptr
 * Return: integer
*/

int check_white_space(const char *lineptr)
{
	while (*lineptr)
	{
		if (_isspace(*lineptr) != 0)
			return (0);
		lineptr++;
	}
	return (1);
}
