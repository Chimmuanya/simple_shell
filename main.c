#include "./cshell.h"

/**
 * main -Entry function for simple shell program
 * @argc: argument count
 * @argv: argument vector -pointer to pointer address
 * @env: environment variabe
 * Return: always 0
*/

int main(int argc, char **argv, char **env)
{
	char *s_prompt = "(CShell) $ ";
	char *lnptr, *lnptr_cpy, *token;
	size_t n = 0;
	ssize_t rd_chars;
	const char *delim = " \n";
	int i, num_tokens = 0;

	_puts(argv[1]);
	while (1)
	{
		_puts(s_prompt);
		rd_chars = getline(&lnptr, &n, stdin);
		if (rd_chars == -1)
		{
			_puts("Exiting shell... \n");
			return (-1);
		}
		lnptr_cpy = malloc(sizeof(char) * rd_chars);
		if (!lnptr_cpy)
		{
			perror("cshell: memory allocation error");
			return (-1);
		}
		_strcpy(lnptr_cpy, lnptr);
		token = strtok(lnptr, delim);
		while (token)
		{
			num_tokens++, token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens), token = strtok(lnptr_cpy, delim);
		for (i = 0; token; i++)
		{
			argv[i] = (char *) malloc(sizeof(char) * strlen(token));
			argv[i] = token, token = strtok(NULL, delim);
		}
		argv[i] = NULL, cmdexec(argv);
	}
	free(lnptr_cpy), free(lnptr);
	return (0);
}
