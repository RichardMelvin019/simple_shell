#include "main.h"

/**
 * path - gets the path of a command
 * @command: command
 * Return: character pointer
*/

char *get_path()
{
	char *location = NULL;
	char *location_copy = NULL;
	char *location_token = NULL;

	location = getenv("PATH");
	if (location)
	{
		location_copy = _strdup(location);
		cmd_len = _strlen(command);
		location_token = strtok(location_copy, delim);
		while (location_token != NULL)
		{
			dir_length = _strlen(location_token);
			file_location = malloc(dir_length + cmd_len + 2);
			_strcpy(file_location, location_token);
			_strcat(file_location, "/");
			_strcat(file_location, command);
			_strcat(file_location, "\0");
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
			return (command);
		return (NULL);
	}
	return (NULL);
}
