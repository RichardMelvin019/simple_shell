#include "main.h"

/**
 * _isspace - space checker
 * @digit: digit
 * Return: digit
*/

int _isspace(int digit)
{
	return (
		digit == ' ' || digit == '\t' ||
		digit == '\v' || digit == '\n' ||
		digit == '\f' || digit == '\r'
	);
}
