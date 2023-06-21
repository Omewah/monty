#include "monty.h"
/**
  * rotl_pfuncs- rotates the stack to the top
  * @h: the head of the stack
  * @num: the line number count
  */
void rotl_pfuncs(stack_t **h,  __attribute__((unused)) unsigned int num)
{
	stack_t *rot = *h, *z;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	z = (*h)->next;
	z->prev = NULL;
	while (rot->next != NULL)
	{
		rot = rot->next;
	}
	rot->next = *h;
	(*h)->next = NULL;
	(*h)->prev = rot;
	(*h) = z;
}

/**
  * rotr_pfuncs- rotates the stack to the bottom
  * @h: the head of the stack
  * @num: the line number count
  */
void rotr_pfuncs(stack_t **h, __attribute__((unused)) unsigned int num)
{
	stack_t *rot;

	rot = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (rot->next)
	{
		rot = rot->next;
	}
	rot->next = *h;
	rot->prev->next = NULL;
	rot->prev = NULL;
	(*h)->prev = rot;
	(*h) = rot;
}

