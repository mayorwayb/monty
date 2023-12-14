#include "monty.h"

/**
 * f_sub - Subtracts the top element from the second top element of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int result, num_nodes;

	current = *head;

	for (num_nodes = 0; current != NULL; num_nodes++)
		current = current->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n - current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
