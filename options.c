#include "monty.h"
#include <stdio.h>

/**
 * push_element - function that pushes an element to the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */
void push_element(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp = *stack;

	if (head->mode)
	{
		push_queue(stack, line_number);
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (is_integer(head->cmd[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(head->cmd[1]);
	new_node->next = NULL;

	if (!(*stack))
	{
		new_node->prev = *stack;
		*stack = new_node;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
}

/**
 * print_all - Function that prints all values on the stack
 * starting from the top of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * execute_operations - Function to execute options
 *
 * @stack: address of double linked list
 *
 */
void execute_operations(stack_t **stack)
{
	int i = 0;

	instruction_t options[] = {
		{"push", push_element},
		{"pall", print_all},
		{"pint", mega_pint},
		{NULL, NULL}
	};

	while (options[i].opcode)
	{
		if (!strcmp(options[i].opcode, head->cmd[0]))
		{
			(*options[i].f)(stack, head->line_number);
			break;
		}
		i++;
	}

	if (!options[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
				head->line_number, head->cmd[0]);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_linked_list - Function to free all linked list
 *
 * @stack: address of double linked list
 *
 */
void free_linked_list(stack_t **stack)
{
	stack_t *tmp = NULL;
	cmds *tmp2 = NULL;

	for (; *stack; *stack = (*stack)->next, free(tmp))
		tmp = *stack;

	for (; head; head = head->next, free(tmp2))
	{
		tmp2 = head;
		free(head->cmd[1]);
		free(head->cmd[0]);
	}
}
