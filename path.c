#include "main.h"

/**
 * path - gets the path of a command
 * @command: command
 * Return: character pointer
*/

char *path(char *command)
{
	char *location, *location_copy;
	int cmd_len, int dir_length;
	char *location_token, *file_location;
	const char *delim = ":";

	location = getenv("PATH");
	if (location)
	{
		location_copy = strdup(location);
		cmd_len = strlen(command);
		location_token = strtok(location_copy, delim);

		while (location_token != NULL)
		{
			dir_length = strlen(location_token);
			file_location = malloc(dir_length + cmd_len + 2);
			strcpy(file_location, location_token);
			strcat(file_location, "/");
			strcat(file_location, command);
			strcat(file_location, "\0");
		}
	}

}
