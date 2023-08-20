#include "main.h"

/**
 * cmd_exe - executes the command
 * @argv: argument vector
 * Return: void
*/

void cmd_exe(char *argv[])
{
	char *command = NULL, *path_command;

	if (argv != NULL)
	{
		command = argv[0];

		path_command = path(command);
	
		if (execve(path_command, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
