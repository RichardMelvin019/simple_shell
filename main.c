#include "main.h"

/**
 * main - Entry point
 * @argc: argument count
 * @agrv: argument vector
 * Return: interger
*/

int main(int argc, char *argv[])
{
	char *prompt = "(SMshell) $ ";
	char *lineptr = NULL, *lineptr_new = NULL, *str_token;
	size_t n = 0;
	ssize_t end_of_line;
	const char *delim = " \n";
	int count_token = 0, j;

	(void)argc;
	while(1)
	{
		write(STDOUT_FILENO, prompt, 13);
		end_of_line = getline(&lineptr, &n, stdin);
		if (end_of_line == -1)
		{
			perror("\nShell exit");
			return (-1);
		}
		lineptr_new = malloc(sizeof(char) * end_of_line);
		if (lineptr_new == NULL)
		{
			perror("memory allocation error\n");
			return (-1);
		}
		strcpy(lineptr_new, lineptr);
		str_token = strtok(lineptr, delim);
		while (str_token != NULL)
		{
			count_token++;
			str_token = strtok(NULL, delim);
		}
		count_token++;
		argv = malloc(sizeof(char *) * count_token);
		str_token = strtok(lineptr_new, delim);
		for (j = 0; str_token != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * strlen(str_token));
			strcpy(argv[j], str_token);
			str_token = strtok(NULL, delim);
		}
		argv[j] = NULL;

		cmd_exe(argv);

		printf("%s\n", lineptr);
	}
	free(lineptr);
	free(lineptr_new);
	return (0);
}
