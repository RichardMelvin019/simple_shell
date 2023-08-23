#include "main.h"

/**
 * _strncmp - string n cmp
 * @s1: s1
 * @s2: s2
 * @n: n
 * Return: integer
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	return (0);
}
