#include "monty.h"


void monty_printchar(stack_t **stack, unsigned int line_number);
void monty_printstring(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);

/**
 * monty_printchar - displays the value of the top elememt
 * @stack: A pointer to the top mode node list.
 * @line_number: The current working line number.
 */
void monty_printchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(line_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(line_number,
                         "value out of range"));
        return;
    }


    printf("%c\n", (*stack)->next->n);
}

/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node list.
 * @line_number: The current working line.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * monty_printstring - Prints the string contained in the list.
 * @stack: A pointer to the top mode node list.
 * @line_number: The current working line
 */
void monty_printstring(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (*stack)->next;


    while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
    {
        printf("%c", temp->n);
        temp = temp->next;
    }


    printf("\n");


    (void)line_number;
}
