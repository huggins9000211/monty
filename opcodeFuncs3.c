#include "monty.h"

/**
 * nop - function subtracts top of the stack from second top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void nop(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}

/**
 * divv - function subtracts top of the stack from second top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void divv(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int number = 0;

	if (((*head) == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	number = number + (*head)->n;
	if (number == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n = temp->n / number;
	temp->prev = NULL;
	(*head) = temp;
}

/**
 * mod - function subtracts top of the stack from second top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int number = 0;

	if (((*head) == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	number = number + (*head)->n;
	if (number == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n = temp->n % number;
	temp->prev = NULL;
	(*head) = temp;
}
