#include "monty.h"
/**
 * push_pfuncs - pushes an element to the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void push_pfuncs(stack_t **h, unsigned int num)
{
	int x, y = 0, z = 0;

	if (mont.stargvIN)
	{
		if (mont.stargvIN[0] == '-')
			y++;
		for (; mont.stargvIN[y] != '\0'; y++)
		{
			if (mont.stargvIN[y] > 57 || mont.stargvIN[y] < 48)
				z = 1; }
		if (z == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(mont.mfile);
			free(mont.linecont);
			memfree_pfuncs(*h);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE); }
	x = atoi(mont.stargvIN);
	if (mont.flagIN == 0)
		addelem_pfuncs(h, x);
	else
		addqueue_pfuncs(h, x);
}

