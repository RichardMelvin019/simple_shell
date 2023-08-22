#include "main.h"

/**
 * _strcpy - copy
 * @destination: dest
 * @source: source
 * Return: void
*/

void _strcpy(char *destination, char *source)
{
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
}
