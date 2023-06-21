#include "monty.h"
/**
 * swap_pfuncs - swaps the top two elements of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void swap_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;
	int lng = 0;
	int z;

	h_stk = *h;
	while (h_stk)
	{
		h_stk = h_stk->next;
		lng++;
	}
	if (lng < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	h_stk = *h;
	z = h_stk->n;
	h_stk->n = h_stk->next->n;
	h_stk->next->n = z;
}

/**
 * add_pfuncs - adds the top two elements of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void add_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;
	int lng = 0;
	int z;

	h_stk = *h;
	while (h_stk)
	{
		h_stk = h_stk->next;
		lng++;
	}
	if (lng < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	h_stk = *h;
	z = h_stk->n + h_stk->next->n;
	h_stk->next->n = z;
	*h = h_stk->next;
	free(h_stk);
}

/**
 * nop_pfuncs - doesn't do anything
 * @h: the head of the stack
 * @num: the line number count
 */
void nop_pfuncs(stack_t **h, unsigned int num)
{
	(void) num;
	(void) h;
}

