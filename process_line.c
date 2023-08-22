#include "main.h"

/**
 * process_line - processes line
 * @num_read: number read
 * @lineptr: lineptr
 * Return: integer
*/
int process_line(char *lineptr, char **argv, char **env, char *filename, char *cmd_location)
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
			get_path(&cmd_location, argv, lineptr_new, lineptr);
			cmd_exe(argv, env, lineptr, lineptr_new, filename, cmd_location);
			free(cmd_location);
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
