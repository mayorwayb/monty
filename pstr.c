#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack,followed by newline
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	(void)counter;

	while (current != NULL)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
