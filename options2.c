#include "monty.h"
#include <stdio.h>

/**
 * print_top_element - Print the top element of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void print_top_element(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%d: can't print, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	while (current->next)
		current = current->next;

	printf("%d\n", current->n);
}

/**
 * pop_element - Remove the top element of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void pop_element(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *previous = NULL;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (!current->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}

	while (current && current->next)
		current = current->next;

	previous = current->prev;
	previous->next = NULL;
	free(current);
}

/**
 * swap_top_elements - Swap the top two elements of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void swap_top_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	size_t count = 1;

	while (current && current->next)
	{
		current = current->next;
		count++;
	}

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (count == 2)
	{
		(*stack)->prev = current;
		current->next = (*stack);
		(*stack)->next = NULL;
		*stack = current;
		(*stack)->prev = NULL;
		return;
	}

	current->prev = current->prev->prev;
	current->prev->next->next = NULL;
	current->next = current->prev->next;
	current->prev->next->prev = current;
	current->prev->next = current;
}

/**
 * add_top_two_elements - Add the top two elements of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	size_t count = 1;

	while (current && current->next)
	{
		current = current->next;
		count++;
	}

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current->prev->n += current->n;
	pop_element(stack, line_number);
}

/**
 * do_nothing - Function that doesn't do anything
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
