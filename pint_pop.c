#include "monty.h"
/**
 * pint_pfuncs - prints the value at the top of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void pint_pfuncs(stack_t **h, unsigned int num)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * pop_pfuncs - removes the top elements of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void pop_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	h_stk = *h;
	*h = h_stk->next;
	free(h_stk);
}

