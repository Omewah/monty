#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct mont_s - a struct containing arguments
 * @stargvIN: the array of strings for the struct argument
 * @mfile: the filename address of the monty program
 * @linecont: the line input string
 * @flagIN: a counter for the stack changes
 * Description: iterates values through out the monty variables
 */
typedef struct mont_s
{
	char *stargvIN;
	FILE *mfile;
	char *linecont;
	int flagIN;
} mont_t;

void memfree_pfuncs(stack_t *h);
void push_pfuncs(stack_t **h, unsigned int num);
void pall_pfuncs(stack_t **h, unsigned int num);
void pint_pfuncs(stack_t **h, unsigned int num);
void pop_pfuncs(stack_t **h, unsigned int num);
void swap_pfuncs(stack_t **h, unsigned int num);
void add_pfuncs(stack_t **h, unsigned int num);
void nop_pfuncs(stack_t **h, unsigned int num);
void sub_pfuncs(stack_t **h, unsigned int num);
void div_pfuncs(stack_t **h, unsigned int num);
void mul_pfuncs(stack_t **h, unsigned int num);
void mod_pfuncs(stack_t **h, unsigned int num);
void pchar_pfuncs(stack_t **h, unsigned int num);
void pstr_pfuncs(stack_t **h, unsigned int num);
void rotl_pfuncs(stack_t **h, __attribute__((unused)) unsigned int num);
void rotr_pfuncs(stack_t **h, __attribute__((unused)) unsigned int num);
void stack_pfuncs(stack_t **h, unsigned int num);
void queue_pfuncs(stack_t **h, unsigned int num);
void addqueue_pfuncs(stack_t **h, int new);
void addelem_pfuncs(stack_t **h, int new);
int execmd(char *linecont, stack_t **st, unsigned int num, FILE *mfile);

extern mont_t mont;

#endif
