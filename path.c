#include "main.h"

/**
 * path - gets the path of a command
 * @command: command
 * Return: character pointer
*/

char *path(char *command)
{
	char *location, *location_copy;
	int cmd_len, dir_length;
	char *location_token, *file_location;
	const char *delim = ":";
	struct stat buffer;

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

			if (stat(file_location, &buffer) == 0)
			{
				free(location_copy);
				return (file_location);
			}
			else
			{
				free(file_location);
				location_token = strtok(NULL, delim);
			}
		}
		free(location_copy);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}

		return (NULL);
	}

	return (NULL);

}
