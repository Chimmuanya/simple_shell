#include "./cshell.h"

/**
 * main -Entry function for simple shell program
 * @argc: argument count
 * @argv: argument vector -pointer to pointer address
 * Return: always 0
*/

int main(int argc, char **argv)
{

	char *s_prompt = "(CShell) $ ";
	char *lnptr;
	size_t n = 0;

	(void)argc, (void)argv;
	printf("%s", s_prompt);

	getline(&lnptr, &n, stdin);
	printf("%s\n", lnptr);

	free(lnptr);


	return (0);
}
