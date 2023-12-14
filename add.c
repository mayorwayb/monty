#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void add_top_two_elements(stack_t **head, unsigned int counter)
{
	int sum = (*head)->n + (*head)->next->n;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	pop_top(head);
	(*head)->n = sum;
}

/**
 * pop_top - Removes the top element from the stack.
 * @head: Pointer to the head of the stack
 * Return: No return value
 */
void pop_top(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return;

	temp = *head;
	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;

	free(temp);
}
