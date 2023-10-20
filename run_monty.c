#include "monty.h"
#include <string.h>


void free_tokens(void);
unsigned int op_toks_len(void);
void (*Mt_opcode_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);
int from_getline(char *line, char *delims);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
    size_t j = 0;

    if (op_toks == NULL)
        return;

    while (op_toks[j])
    {
        free(op_toks[j]);
        j++;
    }
    free(op_toks);
}

/**
 * op_toks_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int op_toks_len(void)
{
    unsigned int toks_len = 0;

    while (op_toks[toks_len])
    {
        toks_len++;
    }
    return (toks_len);
}

/**
 * from_getline - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int from_getline(char *line, char *delims)
{
    int i, j;


    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }


    return (1);
}


/**
 * Mt_opcode_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*Mt_opcode_func(char *opcode))(stack_t**, unsigned int)
{
    instruction_t op_funcs[] = {
        {"push", monty_push},
        {"pall", monty_pall},
        {"pint", monty_pint},
        {"pop", monty_pop},
        {"swap", monty_swap},
        {"add", monty_addition},
        {"nop", monty_nop},
        {"sub", monty_subtraction},
        {"div", monty_division},
        {"mul", monty_multiplication},
        {"mod", monty_modulus},
        {"pchar", monty_printchar},
        {"pstr", monty_printstring},
        {"rotl", monty_rottop},
        {"rotr", monty_rotbot},
        {"stack", queue_to_stack},
        {"queue", stack_to_queue},
        {NULL, NULL}
    };
    int j;

    for (j = 0; op_funcs[j].opcode; j++)
    {
        if (strcmp(opcode, op_funcs[j].opcode) == 0)
            return (op_funcs[j].f);
    }

    return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);


    if (init_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);


    while (getline(&line, &len, script_fd) != -1)
    {
        line_number++;
        op_toks = strdiv(line, DELIMS);
        if (op_toks == NULL)
        {
            if (from_getline(line, DELIMS))
                continue;
            free_stack(&stack);
            return (malloc_error());
        }
        else if (op_toks[0][0] == '#') /* comment line */
        {
            free_tokens();
            continue;
        }
        op_func = *Mt_opcode_func(op_toks[0]);
        if (op_func == NULL)
        {
            free_stack(&stack);
            exit_status = unknown_instruction_error(op_toks[0], line_number);
            free_tokens();
            break;
        }
        prev_tok_len = op_toks_len();
        op_func(&stack, line_number);
        if (op_toks_len() != prev_tok_len)
        {
            if (op_toks && op_toks[prev_tok_len])
                exit_status = atoi(op_toks[prev_tok_len]);
            else
                exit_status = EXIT_FAILURE;
            free_tokens();
            break;
        }
        free_tokens();
    }
    free_stack(&stack);


    if (line && *line == 0)
    {
        free(line);
        return (malloc_error());
    }

    free(line);
    return (exit_status);
}

