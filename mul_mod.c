#include "monty.h"
/**
 * mul_pfuncs - mul the top and second top elements of the stack.
 * @h: the head of the stack
 * @num: the line number count
 */
void mul_pfuncs(stack_t **h, unsigned int num)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	h_stk = *h;
	z = h_stk->next->n * h_stk->n;
	h_stk->next->n = z;
	*h = h_stk->next;
	free(h_stk);
}

/**
 * mod_pfuncs - computes mod of the top and second top element of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void mod_pfuncs(stack_t **h, unsigned int num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	h_stk = *h;
	if (h_stk->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	z = h_stk->next->n % h_stk->n;
	h_stk->next->n = z;
	*h = h_stk->next;
	free(h_stk);
}

