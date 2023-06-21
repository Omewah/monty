#include "monty.h"

/**
 * pall_pfuncs - prints all values on the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void pall_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;
	(void)num;

	h_stk = *h;
	if (h_stk == NULL)
		return;
	while (h_stk)
	{
		printf("%d\n", h_stk->n);
		h_stk = h_stk->next;
	}
}

