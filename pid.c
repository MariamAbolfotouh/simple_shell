#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: 0
 */

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	printf("pppid = %u\n", getppid());
	return (0);
}
