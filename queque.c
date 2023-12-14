#include "monty.h"

/**
 * f_queue - Sets the stack mode to queue (add elements to the tail).
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @head: Head of the stack
 * @n: New value
 * Return: No return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

