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
/*
void rotl(stack_t **head, unsigned int counter)
{
	stack_t *new;
	stack_t *temp;

	(void)counter;
	temp = *head;
	new = malloc(sizeof(stack_t));
	if(new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(temp == NULL || temp->next == NULL)
		return;
	new->n = temp->n;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	new->prev = temp;
	new->next = NULL;
	temp->next = new;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
}
*/
