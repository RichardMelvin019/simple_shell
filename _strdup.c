#include "main.h"

/**
 * _strdup - duplicates
 * @source: source
 * Return: character
*/

char *_strdup(char *source)
{
size_t len;
char *dup;
if (source == NULL)
return (NULL);

len = _strlen(source) + 1;
dup = (char *)malloc(len);
if (dup == NULL)
return (NULL);
_strcpy(dup, source);
return (dup);
}
