#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
