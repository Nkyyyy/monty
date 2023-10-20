#include "monty.h"


void monty_addition(stack_t **stack, unsigned int line_number);
void monty_subtraction(stack_t **stack, unsigned int line_number);
void monty_division(stack_t **stack, unsigned int line_number);
void monty_multiplication(stack_t **stack, unsigned int line_number);
void monty_modulus(stack_t **stack, unsigned int line_number);


/**
 * monty_addition - sums up the first top two values of the list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line.
 *
 */
void monty_addition(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_error(line_number, "add"));
        return;
    }


    (*stack)->next->next->n += (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_subtraction - Subtracts the second value from the top value
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number
 *
 */
void monty_subtraction(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_error(line_number, "sub"));
        return;
    }


    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_division - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line.
 *
 */
void monty_division(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_error(line_number, "div"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }


    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_multiplication - Multiplies the second value from the top
 * @stack: A pointer to the top mode node.
 * @line_number: The current working line number.
 *
 */
void monty_multiplication(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_error(line_number, "mul"));
        return;
    }


    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_modulus - Calculates the modulus of the second value from the
 *             top of a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_error(line_number, "mod"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }


    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pop(stack, line_number);
}