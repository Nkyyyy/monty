#include "monty.h"

/**
 * set_op_tok_error - makes the last element of the op_tokes to be an error code
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
    int lenght = 0, j = 0;
    char *exit_string = NULL;
    char **new_toks = NULL;


    lenght = op_toks_len();
    new_toks = malloc(sizeof(char *) * (lenght + 2));
    if (!op_toks)
    {
        malloc_error();
        return;
    }
    for (j = 0; j < lenght; j++)
    {
        new_toks[j] = op_toks[j];
    }
    exit_string = get_integer(error_code);
    if (!exit_string)
    {
        free(new_toks);
        malloc_error();
        return;
    }
    new_toks[j++] = exit_string;
    new_toks[j] = NULL;
    free(op_toks);
    op_toks = new_toks;
}