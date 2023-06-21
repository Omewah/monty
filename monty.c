#include "monty.h"
mont_t mont = {NULL, NULL, NULL, 0};
/**
* main - a simple monty code interpreter
* @ac: the first argument
* @av: the pointer vector of arguments
* Return: 0 (Success)
*/
int main(int ac, char *av[])
{
	char *linecont;
	FILE *mfile;
	size_t s = 0;
	ssize_t readIN = 1;
	stack_t *st = NULL;
	unsigned int num = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mfile = fopen(av[1], "r");
	mont.mfile = mfile;
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (readIN > 0)
	{
		linecont = NULL;
		readIN = getline(&linecont, &s, mfile);
		mont.linecont = linecont;
		num++;
		if (readIN > 0)
		{
			execmd(linecont, &st, num, mfile);
		}
		free(linecont);
	}
	memfree_pfuncs(st);
	fclose(mfile);
return (0);
}
