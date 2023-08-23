#include "main.h"

/**
 * _strcpy - copy
 * @destination: dest
 * @source: source
 * Return: void
*/

char *_strcpy(char *destination, const char *source)
{
	char *ptr = destination;

	while (*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return (destination);
}
