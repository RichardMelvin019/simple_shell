#include "main.h"

/**
 * _strcat - concatinate
 * @destination: dest
 * @source: source
 * Return: void
*/

char *_strcat(char *destination, const char *source)
{
	char *ptr = destination;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return (destination);
}
