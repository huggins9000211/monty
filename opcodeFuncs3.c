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
	(*head) = temp;
	free((*head)->prev);
	(*head)->prev = NULL;
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
	(*head) = temp;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * rotl - function subtracts top of the stack from second top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void rotl(stack_t **head, unsigned int counter)
{
	stack_t **pp;
	stack_t *temp;
	(void)counter;
	if (!*head || !(*head)->next)
		return;

	pp = &(*head)->next;


	while (*pp && (*pp)->next)
		pp = &(*pp)->next;


	temp = *head;
	*head = *pp;
	*pp = temp;


	(*head)->next = (*pp)->next;
	(*head)->prev = NULL;

	(*pp)->next = NULL;
}

/**
 * rotr - function subtracts top of the stack from second top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void rotr(stack_t **head, unsigned int counter)
{
	stack_t *copy;
	stack_t *extra;
	(void)counter;

	if (!*head || !(*head)->next)
		return;

	copy = *head;
	while (copy->next->next != NULL)
	{
		copy = copy->next;
	}
	extra = copy->next;
	copy->next = NULL;
	while (copy->prev != NULL)
	{
		copy = copy->prev;
	}
	extra->next = copy;
	extra->prev = NULL;
	*head = extra;
}
