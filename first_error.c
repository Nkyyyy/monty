#include "monty.h"


int use_error(void);
int fopen_error(char *filename);
int unknown_instruction_error(char *opcode, unsigned int line_number);
int malloc_error(void);
int no_int_error(unsigned int line_number);


/**
 * use_error - usage error messages is printed
 *
 * Return: (EXIT_FAILURE) always.
 */
int use_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
}


/**
 * malloc_error - error message when you can not malloc anymore
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}


/**
 * fopen_error - error messages 
 * @filename: Name of file failed to  not possible to open the fileopen
 *
 * Return: (EXIT_FAILURE) always.
 */
int fopen_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}


/**
 * unknown_instruction_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_isntruction_error(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n",
        line_number, opcode);
    return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    return (EXIT_FAILURE);
}
