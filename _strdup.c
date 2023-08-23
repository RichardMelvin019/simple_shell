#include "main.h"

/**
 * _strdup - duplicates
 * @source: source
 * Return: character
*/

char *_strdup(const char *source)
{
	size_t len;
	char *dup;

	len = _strlen(source) + 1;
	dup = (char *)malloc(len * sizeof(char));
	if (dup != NULL)
		_strcpy(dup, source);
	return (dup);
}
