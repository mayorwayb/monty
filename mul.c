#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int len = 0, result;

	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
