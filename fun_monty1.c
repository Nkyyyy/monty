#include "monty.h"


void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
int check_mode(stack_t *stack);

/**
 * monty_push - adds an element to the stack list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working location
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new, *temp;
    int j = 0;


    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        set_op_tok_error(malloc_error());
        return;
    }


    if (op_toks[1] == NULL)
    {
        set_op_tok_error(no_int_error(line_number));
        return;
    }


    while (op_toks[1][j])
    {
        if (op_toks[1][j] == '-' && j == 0)
            continue;
        if (op_toks[1][j] < '0' || op_toks[1][j] > '9')
        {
            set_op_tok_error(no_int_error(line_number));
            return;
        }
        j++;
    }
    new->n = atoi(op_toks[1]);


    if (check_mode(*stack) == STACK)
    {
        temp = (*stack)->next;
        new->prev = *stack;
        new->next = temp;
        if (temp)
            temp->prev = new;
        (*stack)->next = new;
    }
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        new->prev = temp;
        new->next = NULL;
        temp->next = new;
    }
}




/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pint_error(line_number));
        return;
    }


    printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Deletes the top value element of the list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *next = NULL;


    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pop_error(line_number));
        return;
    }


    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * swap_monty - exchanges the top two value of the list.
 * @stack: A pointer to the top mode  list.
 * @line_number: current location
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_error(line_number, "swap"));
        return;
    }


    temp = (*stack)->next->next;
    (*stack)->next->next = temp->next;
    (*stack)->next->prev = temp;
    if (temp->next)
        temp->next->prev = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;
}

/**
 * monty_pall - gets the values of the list.
 * @stack: A pointer to the top mode node of the list.
 * @line_number: The current working line
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;


    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)line_number;
}