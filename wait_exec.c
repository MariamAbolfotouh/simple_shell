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

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

		printf("Before exec.\n");
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
		printf("After exec.\n");
		return (0);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
