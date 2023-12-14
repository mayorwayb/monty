#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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

typedef struct {
   bus_t bus = {NULL, NULL, NULL, 0};
} bus_t;

extern bus_t bus(bus_t bus = {NULL, NULL, NULL, 0});
void add_top_two_elements(stack_t **head, unsigned int counter);
void pop_top(stack_t **head);
void push_to_stack(stack_t **head, int value);
void divide_top_two_elements(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
int main(int argc, char *argv[]);
bus_t bus = {NULL, NULL, NULL, 0};
void f_mod(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pint(stack_t **head, unsigned int counter);

#endif
