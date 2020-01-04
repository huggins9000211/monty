#include "monty.h"
/**
 * strdigit - function checks if string contains numeric digits
 *
 * @str: char * to input string
 *
 * Return: 1 if string has only numeric digits, 0 if it doesn't
 */

int strdigit(char *str)
{
	char *copy = str;
	int i = 0;

	if (copy[i] == '-')
		i = 1;
	while (copy[i] != '\0')
	{
		if (!isdigit(copy[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * freestack - function frees stack_t linked list
 *
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
    stack_t *last;
    while (head != NULL)
    {
        last = head;
        head = last->next;
        free(last);
    } 
}
