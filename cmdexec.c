#include "./cshell.h"

/**
 * cmdexec -function to handle cshell's commands
 * @argv: pointer to argv vector (array of strings)
 * Return: void
*/

void cmdexec(char *argv[])
{
	char *cmd = NULL, *rl_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		puts(cmd);
		rl_cmd = locate_cmd(cmd);
		if (execve(rl_cmd, argv, NULL) == -1)
			perror("Error:");
	}
}
