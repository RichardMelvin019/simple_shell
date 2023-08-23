#include "main.h"

/**
 * _getenv - gets environment
 * @name: environment name
 * Return: character
*/

char *_getenv(const char *name)
{
	char **env;
	size_t name_length;

	if (name == NULL || name[0] == '\0')
	{
		return (NULL);
	}

	name_length = strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
		return (*env + name_length + 1);
		}
	}

	return (NULL);
}
