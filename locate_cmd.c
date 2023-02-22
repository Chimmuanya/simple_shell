#include "cshell.h"

/**
 * locate_cmd -function to locate execuatable
 * @cmd: executable name
 * Return: absolute path to executable
*/
char *locate_cmd(char *cmd)
{
	size_t cmdlen, dir_len;
	char *path, *pathcpy, *p_token, *file_pth;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{
		pathcpy = (char *) malloc(sizeof(char) * strlen(path) + 1);
		strcpy(pathcpy, path);
		cmdlen = strlen(cmd);
		p_token = strtok(pathcpy, ":");
		while (p_token != NULL)
		{
			dir_len = strlen(p_token);
			cmdlen = strlen(cmd);
			file_pth = malloc(sizeof(char) * (cmdlen + dir_len + 2));
			strcpy(file_pth, p_token);
			strcat(file_pth, "/");
			strcat(file_pth, cmd);
			strcat(file_pth, "\0");
			/*does path exist*/
			if (stat(file_pth, &buff) == 0)
			{
				free(pathcpy);
				return (file_pth);
			}
			else
			{
				free(file_pth);
				p_token = strtok(NULL, ":");
			}
		}
		print_err(cmd, "Executable not found\n");
		free(pathcpy);
		/*is cmd itself a valid path*/
		if (stat(cmd, &buff) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}

/**
 * start_child - start a child process
 * @argv: argument vector
 * @env: envp passed from main
 * Return: void
*/
void start_child(char **argv, char **env)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
		perror("Error:");
	if (child == 0)
	{
		if (execve(locate_cmd(argv[0]), argv, env))
		{
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			if (status == 126)
				print_err(argv[0], "permission denied\n");
		}
	}
}
