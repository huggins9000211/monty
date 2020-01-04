#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global Variable */
extern stack_t *head;
/* Prototypes */
void add_dnodeint(stack_t **head, const int n);
int strdigit(char *str);
void (*get_op_func(char *s))(stack_t **, unsigned int);
void print_dlistint(stack_t **h, unsigned int counter);
void pint(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void execute(char *opcode, unsigned int counter, char *data);
void free_dlistint(stack_t *head);
void divv(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
#endif
