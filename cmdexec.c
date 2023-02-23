#include "./cshell.h"

/**
 * cmdexec -function to handle cshell's commands
 * @argv: pointer to argv vector (array of strings)
 * @env: environ
 * Return: void
*/

void cmdexec(char *argv[], char **env)
{
	char *cmd = NULL;
	pid_t pid;

	pid = fork();
	if (argv)
	{
		cmd = argv[0];
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			if (execve(cmd, argv, env))
			{
				if (errno == EACCES)
					exit(126);
				_putserr("File not Found\n");
				exit(1);
			}
		}
		else
			wait(NULL);
	}
}


/**
 * _strcpy - entry function
 * copies the string pointed to by src, including the terminating null byte(\0)
 * , to the buffer pointed to by dest
 * @src: source string
 * @dest: destination buffer to be copied to.
 * Return: dest pointer
 */
char *_strcpy(char *dest, char *src)
{
	long len, index;

	len = 0;

	if (src)
	{
		while (*src != '\0')
		{
			len++;
			src++;
		}

		src -= len;
		for (index = 0; index <= len; index++)
			dest[index] = src[index];

		return (dest);
	}

	return (dest);

}
