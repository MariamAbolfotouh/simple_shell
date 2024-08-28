#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * token_str - jkjg
 *
 * @inp: input
 * @delim: delimeter
 *
 * Return: tkens
 */

char **token_str(char *inp, char *delim)
{
	int size = 1;
	char **tkens;
	char *tken;
	int i;

	tkens = malloc(size * sizeof(char *));
	tken = strtok(inp, delim);
	while (tken != NULL)
	{
		i = size - 1;
		size++;
		tkens = realloc(tkens, size * sizeof(char *));
		tkens[i] = malloc(strlen(tken) * sizeof(char));
		strcpy(tkens[i], tken);
		tken = strtok(NULL, delim);
	}
	tkens[size - 1] = NULL;
	return (tkens);
}

/**
 * prt_tkens - df
 *
 * @tkens: tokens
 */

void prt_tkens(char **tkens)
{
	int i = 0;

	while (tkens[i] != NULL)
	{
		printf("%s\n", tkens[i++]);
	}
}

int main(void)
{
	char *inp = NULL;
	size_t l_inp = 0;
	int status;
	pid_t child_pid;

	if (!isatty(STDIN_FILENO))
	{
		printf("non_interactive\n");
		return (0);
	}
	while (1)
	{
		printf("command: ");
		int rd = getline(&inp, &l_inp, stdin);

		if (rd == -1)
		{
			free(inp);
			return (1);
		}
		else
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);	}
			if (child_pid == 0)
			{
				char **argv = token_str(inp, " \t\n");

				prt_tkens(argv);
				if (execve(argv[0], argv, NULL) == -1)
					perror("Error:");
				return (0);	}
			wait(&status);	}
			free(inp);
			inp = NULL;	}
	free(inp);
	return (0);
}
