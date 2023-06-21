#include "monty.h"
/**
 * stack_pfuncs - sets the data to stack (LIFO)
 * @h: the head of the stack
 * @num: the line number count
 */
void stack_pfuncs(stack_t **h, unsigned int num)
{
	(void)h;
	(void)num;
	mont.flagIN = 0;
}

/**
 * queue_pfuncs - sets the data to queue (FIFO)
 * @h: the head of the stack
 * @num: the line number count
 */
void queue_pfuncs(stack_t **h, unsigned int num)
{
	(void)h;
	(void)num;
	mont.flagIN = 1;
}

/**
 * addqueue_pfuncs - add node to the tail stack
 * @h: head of the stack
 * @new: the new element added to queue
 */
void addqueue_pfuncs(stack_t **h, int new)
{
	stack_t *n_elem;
	stack_t *z;

	z = *h;
	n_elem = malloc(sizeof(stack_t));
	if (n_elem == NULL)
	{
		printf("Error: No new element to queue\n");
	}
	n_elem->n = new;
	n_elem->next = NULL;
	if (z)
	{
		while (z->next)
			z = z->next;
	}
	if (!z)
	{
		*h = n_elem;
		n_elem->prev = NULL;
	}
	else
	{
		z->next = n_elem;
		n_elem->prev = z;
	}
}

/**
 * addelem_pfuncs - adds a new element to the head of the stack
 * @h: the head of the stack
 * @new: the new element to be added
 */
void addelem_pfuncs(stack_t **h, int new)
{

	stack_t *n_elem;
	stack_t *z;

	z = *h;
	n_elem = malloc(sizeof(stack_t));
	if (n_elem == NULL)
	{ printf("Error: No new element to add\n");
		exit(0); }
	if (z)
		z->prev = n_elem;
	n_elem->n = new;
	n_elem->next = *h;
	n_elem->prev = NULL;
	*h = n_elem;
}

