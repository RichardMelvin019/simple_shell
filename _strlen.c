#include "main.h"

/**
 * _strlen - string length
 * @s: s
 * Return: size_t
*/

size_t _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
