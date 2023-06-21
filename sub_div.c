#include "monty.h"
/**
 * sub_pfuncs - sub top element from second top element
 * @h: the head of the stack
 * @num: the line number count
*/
void sub_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *z;
	int x;
	int st_nde;

	z = *h;
	for (st_nde = 0; z != NULL; st_nde++)
		z = z->next;
	if (st_nde < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	z = *h;
	x = z->next->n - z->n;
	z->next->n = x;
	*h = z->next;
	free(z);
}

/**
 * div_pfuncs - divides the top two elements of the stack.
 * @h: the head of the stack
 * @num: the line number count
 */
void div_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;
	int lng = 0, z;

	h_stk = *h;
	while (h_stk)
	{
		h_stk = h_stk->next;
		lng++;
	}
	if (lng < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
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
	z = h_stk->next->n / h_stk->n;
	h_stk->next->n = z;
	*h = h_stk->next;
	free(h_stk);
}

