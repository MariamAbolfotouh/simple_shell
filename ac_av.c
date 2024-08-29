#include <stdio.h>

/**
 * main - Entry point
 *
 * @ac: ihi
 * @av: ave
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int n;

	printf("the count of the arguments is %d\n", ac);
	printf("the first argument is %s\n", av[0]);

	for (n = 0; n < ac; n++)
	{
		printf("%d : %s\n", n + 1, av[n]);
	}

	return (0);
}
