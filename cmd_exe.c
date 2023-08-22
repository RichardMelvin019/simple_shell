#include "main.h"

/**
 * cmd_exe - executes the command
 * @argv: argument vector
 * Return: void
*/

int cmd_exe(char **argv, char **env, char *lineptr,
	char *lineptr_new, char *filename, char *command, int loop_count)
{
	pid_t pid;
	int execve_num;

	if (access(command, F_OK) != -1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror(filename);
			memory_free(lineptr, lineptr_new, argv);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve_num = execve(command, argv, env);
			if (execve_num == -1)
			{
				perror(filename);
				memory_free(lineptr, lineptr_new, argv);
			}
			else
				memory_free(lineptr, lineptr_new, argv);
		}
		else
			wait(0);
	}
	else
		get_path_error(filename, argv, lineptr_new, lineptr, loop_count);
	return (0);
}

int memory_free(char *lineptr, char *lineptr_new, char **argv)
{
	free(argv);
	free(lineptr_new);
	free(lineptr);

	return (0);
}

int get_path_error(char *filename, char **argv, char *lineptr_new, char *lineptr, int loop_count)
{
	_printf("%s: %d: %s: not found\n", filename, loop_count, argv[0]);
	if (issatty(STDIN_FILENO) == 0)
	{
		memory_free(lineptr, lineptr_new, argv);
		exit(127);
	}
	memory_free(lineptr, lineptr_new, argv);
	return (0);
}
