#include "monty.h"
#include <stdio.h>

/**
 * switch_to_stack_mode - Changes structure to stack
 *
 * @stack: Address of doubly linked list
 * @line_number: Line number
 */
void switch_to_stack_mode(stack_t **stack, unsigned int line_number)
{
	cmds *current_cmd = head;
	(void)stack;
	(void)line_number;

	if (current_cmd->mode)
	{
		for (; current_cmd; current_cmd = current_cmd->next)
			current_cmd->mode = 0;
	}
}

/**
 * push_on_queue_mode - Push on queue mode
 *
 * @stack: Address of doubly linked list
 * @line_number: Line number
 */
void push_on_queue_mode(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	if (is_integer(head->cmd[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_all(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(head->cmd[1]);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
