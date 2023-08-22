#include "main.h"

/**
 * cmd_exe - executes the command
 * @argv: argument vector
 * Return: void
*/

int cmd_exe(char **argv, char **env, char *lineptr,
	char *lineptr_new, char *filename, char *command)
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
		perror(filename);
	return (0);
}

int memory_free(char *lineptr, char *lineptr_new, char **argv)
{
	free(argv);
	free(lineptr_new);
	free(lineptr);

	return (0);
}
