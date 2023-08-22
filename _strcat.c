#include "main.h"

/**
 * _strcat - concatinate
 * @destination: dest
 * @source: source
 * Return: void
*/

void _strcat(char *destination, const char *source)
{
	while (*destination != '\0')
	{
		destination++;
	}
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}
