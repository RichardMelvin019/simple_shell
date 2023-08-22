#include "main.h"

char *_getenv(const char *env_name, char **env)
{
	int i;
	char *var_name;
	char *var_value;
	size_t env_name_len;

	if (name == NULL || _strlen(name) == 0)
		return NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		var_name = env[i];
		var_value = _strchr(var_name, '=');
		env_name_len = var_value - var_name;
		if (var_name != NULL)
		{
			if (env_name_len == _strlen(var_name) && _strncmp(var_name, env_name, env_name_len) == 0)
				return var_value + 1;
		}
	}

	return NULL;
}
