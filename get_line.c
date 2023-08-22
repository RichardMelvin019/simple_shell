#include "main.h"

/**
 * get_line - getline
 * Return: interger
*/

int get_line(char **env, char *filename)
{
	char *prompt = "(SMshell) $ ";

	while (1)
	{
		char *lineptr = NULL;
		char **argv = NULL;
		char *cmd_location = NULL;
		size_t buff_size = 0;
		ssize_t num_read = 0;

		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, prompt, 13);
		num_read = getline(&lineptr, &buff_size, stdin);
		if (num_read == -1 || num_read == 0)
			check_getline(lineptr, buff_size);
		else if (num_read == 1 && lineptr[0] == '\n')
		{
			free(lineptr);
			continue;
		}
		else
		{
			process_line(lineptr, argv, env, filename, cmd_location);
		}
	}
	return (0);
}

/**
 * check_getline - checks getline
 * @lineptr: lineptr
 * @buff_size: buffer size
 * Return: integer
*/

int check_getline(char *lineptr, size_t buff_size)
{
	if (lineptr == NULL || buff_size == 0)
		exit(EXIT_FAILURE);
	else
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
