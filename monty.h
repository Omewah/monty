#ifndef MONTY_H
#define MONTY_H

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
 * @stargvIN: the value for the struct argument
 * @mfile: the pointer address to the monty file location
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

void push_pfuncs(stack_t **h, unsigned int n);
void pall_pfuncs(stack_t **h, unsigned int n);

extern mont_t mont;

#endif
