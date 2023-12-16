#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct commands - singly linked list of parsed commands.
 * @line_number: line number of the script.
 * @cmd: [command, argument] array
 * @next: next node.
 * Return: address of linked list.
 */

typedef struct commands
{
	short mode;
	unsigned int line_number;
	char *cmd[2];
	struct commands *next;
} cmds;

extern cmds *head;
void push_element(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void execute_operations(stack_t **stack);
void free_linked_list(stack_t **stack);
void print_top_element(stack_t **stack, unsigned int line_number);
void pop_element(stack_t **stack, unsigned int line_number);
void swap_top_elements(stack_t **stack, unsigned int line_number);
void add_top_two_elements(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void subtract_top_elements(stack_t **stack, unsigned int line_number);
void divide_top_elements(stack_t **stack, unsigned int line_number);
void multiply_top_elements(stack_t **stack, unsigned int line_number);
void modulo_top_elements(stack_t **stack, unsigned int line_number);
void print_char_at_top(stack_t **stack, unsigned int line_number);
void print_string_at_top(stack_t **stack, unsigned int line_number);
int is_integer(char *s);
void rotate_stack_to_top(stack_t **stack, unsigned int line_number);
void rotate_stack_to_bottom(stack_t **stack, unsigned int line_number);
void change_to_queue_mode(stack_t **stack, unsigned int line_number);
void switch_to_stack_mode(stack_t **stack, unsigned int line_number);
void push_on_queue_mode(stack_t **stack, unsigned int line_number);
cmds *build_command_node(cmds **head, char *command_line, int line_number);
int handle_comments(char **line);
int is_blank(char *s);
int main(int argc, char **argv);
void free_stack(stack_t **stack);
void free_command_node(cmds **node);
int handle_comments(char **s);
void push_queue(stack_t **stack, unsigned int line_number);
void free_all(stack_t **stack);
void mega_pint(stack_t **stack, unsigned int line_number);
void execute_ops(stack_t **stack);
int dprintf(int fd, const char *format, ...);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
