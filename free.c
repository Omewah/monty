#include "monty.h"
/**
* memfree_pfuncs - a function that frees a doubly LL
* @h: the head of the stack
*/
void memfree_pfuncs(stack_t *h)
{
	stack_t *z;

	z = h;
	while (h)
	{
		z = h->next;
		free(h);
		h = z;
	}
}
