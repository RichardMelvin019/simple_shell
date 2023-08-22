#include "main.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: interger
*/
int main(int argc, char **argv, char **env)
{
	char *filename = argv[0];
	
	if (argc == 1)
	{
		get_line(env, filename);
	}
	return (0);
}
