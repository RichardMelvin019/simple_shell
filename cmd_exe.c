#include "main.h"

/**
 * cmd_exe - executes the command
 * @argv: argument vector
 * Return: void
*/

void cmd_exe(char *argv[])
{
	char *command = NULL;

	if (argv != NULL)
	{
		command = argv[0];
	}
	if (execve(command, argv, NULL) == -1)
	{
		perror("Error");
	}
}
