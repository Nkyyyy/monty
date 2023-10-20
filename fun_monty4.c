#include "monty.h"

void stack_to_queue(stack_t **stack, unsigned int line_number);
void monty_rottop(stack_t **stack, unsigned int line_number);
void monty_rotbot(stack_t **stack, unsigned int line_number);
void queue_to_stack(stack_t **stack, unsigned int line_number);


/**
 * stack_to_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void stack_to_queue(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}


/**
 * monty_rottop - This Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top node list.
 * @line_number: The current working line.
 */
void monty_rottop(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;


    (void)line_number;
}


/**
 * monty_rotbot - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node.
 * @line_number: The current working line number.
 */
void monty_rotbot(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;


    (void)line_number;
}


/**
 * queue_to_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node.
 * @line_number: The current working line
 */
void queue_to_stack(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = STACK;
    (void)line_number;
}
