#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void divide_top_two_elements(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	int result = (*head)->next->n / (*head)->n;

	pop_top(head);
	(*head)->n = result;
}
