#include "monty.h"
#include <stdio.h>

/**
 * subtract_top_elements - Subtract the top two elements of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void subtract_top_elements(stack_t **stack, unsigned int line_number)
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
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current->prev->n -= current->n;
	pop_element(stack, line_number);
}

/**
 * divide_top_elements - Divide the top two elements of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void divide_top_elements(stack_t **stack, unsigned int line_number)
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
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (!(current->n))
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current->prev->n /= current->n;
	pop_element(stack, line_number);
}

/**
 * multiply_top_elements - Multiply the top two elements of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void multiply_top_elements(stack_t **stack, unsigned int line_number)
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
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current->prev->n *= current->n;
	pop_element(stack, line_number);
}

/**
 * modulo_top_elements - Compute the rest of the division
 * of the second top element by the top element of the stack
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void modulo_top_elements(stack_t **stack, unsigned int line_number)
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
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (!(current->n))
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current->prev->n %= current->n;
	pop_element(stack, line_number);
}

/**
 * print_char_at_top - Print the char at the top of the stack followed by '\n'
 *
 * @stack: Address of double linked list
 * @line_number: Line number
 *
 */
void print_char_at_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	while (current->next)
		current = current->next;

	if (current->n < 0 || current->n > 126)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}
