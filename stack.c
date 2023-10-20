#include "monty.h"
#include <string.h>


void free_stack(stack_t **stack);
int initiate_stack(stack_t **stack);
int check_mode(stack_t *stack);


/**
 * free_stack - Frees a stack.
 * @stack: the stack
 */
void free_stack(stack_t **stack)
{
    stack_t *temp = *stack;


    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}


/**
 * initiate_stack - starts the stack
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return:  EXIT_FAILURE on error
 *         Otherwise - EXIT_SUCCESS.
 */
int initiate_stack(stack_t **stack)
{
    stack_t *t;


    t = malloc(sizeof(stack_t));
    if (t == NULL)
        return (malloc_error());


    t->n = STACK;
    t->prev = NULL;
    t->next = NULL;


    *stack = t;


    return (EXIT_SUCCESS);
}


/**
 * mode_check - Checks waht mode the stack is.
 * @stack: A pointer to the stack
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int mode_check(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}
