#include "monty.h"

/**
 * push_to_stack - Adds a new node to the head of the stack
 * @head: Pointer to the head of the stack
 * @value: Value to be added to the new node
 * Return: No return value
 */
void push_to_stack(stack_t **head, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}
