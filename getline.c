#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *inp = NULL;
	size_t l_inp = 0;
	
	while (1)
	{
		printf("command: ");
		int rd = getline(&inp, &l_inp, stdin);

		if (rd == -1)
		{
			free(inp);
			printf("\nthe program failed to read the line or it was interrupted\n");
			return (1);
		}
		else
		{
			printf("%s\n", inp);
			/*printf("the num of the chararcters read is %d\n", rd);
			printf("i/p was %s\n", inp);
			*/
			char *tkn = strtok(inp, " \t\n");
			while (tkn != NULL)
			{
				printf("%s\n", tkn);
				tkn = strtok(NULL, " \t\n");
			}
		}
		free(inp);
		inp = NULL;
	}

	free(inp);
	return (0);
}
