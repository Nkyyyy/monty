#include <stdlib.h>
#include "monty.h"

int numbase_len(unsigned int number, unsigned int base);
char *get_integer(int number);
unsigned int _abs(int j);
void buff_filler(unsigned int number, unsigned int base,
            char *buff, int buffer_size);

/**
 * numbase_len - gets length of buffer for an unsigned int
 * @number: the length needed
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed
 */
int numbase_len(unsigned int number, unsigned int base)
{
    int lenght = 1;

    while (number > base - 1)
    {
        lenght++;
        number /= base;
    }
    return (lenght);
}
/**
 * get_integer - converts string to integer
 * @number: number to be converted
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_integer(int number)
{
    int len = 0;
    long digit_l = 0;
    unsigned int temp;
    
    char *ret;

    temp = _abs(number);
    len = numbase_len(temp, 10);


    if (number < 0 || digit_l < 0)
        len++; /* negative sign */
    ret = malloc(len + 1);
    if (!ret)
        return (NULL);


    buff_filler(temp, 10, ret, len);
    if (number < 0 || digit_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * _abs - prints the absolute value of an integer
 * @j:  absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int j)
{
    if (j < 0)
        return (-(unsigned int)j);
    return ((unsigned int)j);
}

/**
 * buff_filler - it add the correct number to the buffer
 * @number: number to convert to string
 * @base: base of number; up to base 36
 * @buff: buffer to fill with result of conversion
 * @buffer_size: size of buffer in bytes
 *
 * Return: always void.
 */
void buff_filler(unsigned int number, unsigned int base,
            char *buff, int buffer_size)
{
    int mod, j = buffer_size - 1;


    buff[buffer_size] = '\0';
    while (j >= 0)
    {
        mod = number % base;
        if (mod > 9)
            buff[j] = mod + 87;
        else
            buff[j] = mod + '0';
        number /= base;
        j--;
    }
}
