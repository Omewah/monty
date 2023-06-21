#include "monty.h"
/**
 * pchar_pfuncs - prints the char at the top of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void pchar_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;

	h_stk = *h;
	if (!h_stk)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	if (h_stk->n > 127 || h_stk->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		fclose(mont.mfile);
		free(mont.linecont);
		memfree_pfuncs(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h_stk->n);
}

/**
 * pstr_pfuncs - prints the str that starts at the top of the stack
 * @h: the head of the stack
 * @num: the line number count
 */
void pstr_pfuncs(stack_t **h, unsigned int num)
{
	stack_t *h_stk;
	(void)num;

	h_stk = *h;
	while (h_stk)
	{
		if (h_stk->n > 127 || h_stk->n <= 0)
		{
			break;
		}
		printf("%c", h_stk->n);
		h_stk = h_stk->next;
	}
	printf("\n");
}

