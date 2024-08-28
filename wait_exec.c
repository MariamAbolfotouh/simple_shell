#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	int i = 0;

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			return (0);
		}
		wait(&status);
		printf("Oh, it's all better now\n");
		i = i + 1;
	}
	return (0);
}
