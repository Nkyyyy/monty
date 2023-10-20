#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* ERROR MESSAGES & ERROR CODES */
int use_error(void);
int fopen_error(char *filename);
int unknown_instruction_error(char *opcode, unsigned int line_number);
int malloc_error(void);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int op_toks_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);


/*INTEGER TO STRING*/
int numbase_len(unsigned int number, unsigned int base);
char *get_integer(int number);
unsigned int _abs(int j);
void buff_filler(unsigned int number, unsigned int base,
            char *buff, int buffer_size);


/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
void monty_addition(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_subtraction(stack_t **stack, unsigned int line_number);
void monty_division(stack_t **stack, unsigned int line_number);
void monty_multiplication(stack_t **stack, unsigned int line_number);
void monty_modulus(stack_t **stack, unsigned int line_number);
void monty_printchar(stack_t **stack, unsigned int line_number);
void monty_printstring(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void stack_to_queue(stack_t **stack, unsigned int line_number);
void monty_rottop(stack_t **stack, unsigned int line_number);
void monty_rotbot(stack_t **stack, unsigned int line_number);
void queue_to_stack(stack_t **stack, unsigned int line_number);


/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strdiv(char *string, char *delims);
char *get_integer(int number);

#endif
