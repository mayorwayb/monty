#include "monty.h"

/**
 * f_pall - Prints the elements of the stack.
 * @head: Stack head
 * @counter: Unused parameter
 * Return: No return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	(void)counter;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
