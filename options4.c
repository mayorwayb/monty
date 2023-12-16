#include "monty.h"
#include <stdio.h>

/**
 * print_string_at_top - Prints the string starting at the top of the stack + '\n'
 *
 * @stack: Address of doubly linked list
 * @line_number: Line number
 */
void print_string_at_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char str[1028];
	size_t i = 0;
	(void)line_number;

	if (!current)
	{
		printf("\n");
		return;
	}

	for (; current->next; current = current->next)
		;

	for (; current && current->n; current = current->prev, i++)
	{
		if (current->n <= 0 || current->n > 126)
			break;

		str[i] = current->n;
	}

	str[i] = '\0';
	printf("%s\n", str);
}

/**
 * is_integer - Checks if s could be converted to a decimal int
 *
 * @s: Source string
 * Return: 0 on success, otherwise 1
 */
int is_integer(char *s)
{
	size_t i;

	if (!s)
		return (1);

	for (i = 0; s[i]; i++)
	{
		if ((s[i] < 48 || s[i] > 57) && (s[i] != '-'))
			return (1);
	}

	return (0);
}

/**
 * rotate_stack_to_top - Rotates the stack to the top
 *
 * @stack: Address of doubly linked list
 * @line_number: Line number
 */
void rotate_stack_to_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!(*stack) || !((*stack)->next))
		return;

	for (; tmp->next; tmp = tmp->next)
		;

	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * rotate_stack_to_bottom - Rotates the stack to the bottom
 *
 * @stack: Address of doubly linked list
 * @line_number: Line number
 */
void rotate_stack_to_bottom(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!(*stack) || !((*stack)->next))
		return;

	for (; tmp->next; tmp = tmp->next)
		;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

/**
 * change_to_queue_mode - Changes structure to queue mode
 *
 * @stack: Address of doubly linked list
 * @line_number: Line number
 */
void change_to_queue_mode(stack_t **stack, unsigned int line_number)
{
	cmds *current_cmd = head;
	(void)stack;
	(void)line_number;

	if (!current_cmd->mode)
	{
		for (; current_cmd; current_cmd = current_cmd->next)
			current_cmd->mode = 1;
	}
}
