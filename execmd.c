#include "monty.h"
/**
* execmd - a function that executes the opcode functions
* @st: the head of the stack Linked List
* @num: the line number count
* @mfile: the filename address of the monty program
* @linecont: the line input string
* Return: 1 (Success), Else 0
*/
int execmd(char *linecont, stack_t **st, unsigned int num, FILE *mfile)
{
	instruction_t st_opcd[] = {
				{"push", push_pfuncs}, {"pall", pall_pfuncs}, {"pint", pint_pfuncs},
				{"pop", pop_pfuncs},
				{"swap", swap_pfuncs},
				{"add", add_pfuncs},
				{"nop", nop_pfuncs},
				{"sub", sub_pfuncs},
				{"div", div_pfuncs},
				{"mul", mul_pfuncs},
				{"mod", mod_pfuncs},
				{"pchar", pchar_pfuncs},
				{"pstr", pstr_pfuncs},
				{"rotl", rotl_pfuncs},
				{"rotr", rotr_pfuncs},
				{"queue", queue_pfuncs},
				{"stack", stack_pfuncs},
				{NULL, NULL}
				};
	unsigned int x = 0;
	char *opcmd;

	opcmd = strtok(linecont, " \n\t");
	if (opcmd && opcmd[0] == '#')
		return (0);
	mont.stargvIN = strtok(NULL, " \n\t");
	while (st_opcd[x].opcode && opcmd)
	{
		if (strcmp(opcmd, st_opcd[x].opcode) == 0)
		{	st_opcd[x].f(st, num);
			return (0);
		}
		x++;
	}
	if (opcmd && st_opcd[x].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", num, opcmd);
		fclose(mfile);
		free(linecont);
		memfree_pfuncs(*st);
		exit(EXIT_FAILURE); }
	return (1);
}
