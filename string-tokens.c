#include <stdlib.h>

int word_length(char *string, char *delims);
int get_word_count(char *string, char *delims);
char *next_word(char *string, char *delims);
char **strdiv(char *string, char *delims);
int check_delim(char charaa, char *delims);


/**
 * get_word_count - counts the words in a string
 *
 * @string: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */


int get_word_count(char *string, char *delims)
{
    int wcount = 0, pend = 1, j = 0;


    while (*(string + j))
    {
        if (check_delim(string[j], delims))
            pend = 1;
        else if (pend)
        {
            pend = 0;
            wcount++;
        }
        j++;
    }
    return (wcount);
}

/**
 * next_word - form the new word in a string
 *
 * @string: the string he form the next word
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */


char *next_word(char *string, char *delims)
{
    int pend = 0;
    int j = 0;


    while (*(string + j))
    {
        if (check_delim(string[j], delims))
            pend = 1;
        else if (pend)
            break;
        j++;
    }
    return (string + j);
}

/**
 * strdiv- takes a string and seperates its words
 *
 * @string: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */


char **strdiv(char *string, char *delims)
{
    char **words = NULL;
    int wc, wordLen, n, i = 0;


    if (string == NULL || !*string)
        return (NULL);
    wc = get_word_count(string, delims);

    if (wc == 0)
        return (NULL);
    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (i < wc)
    {
        wordLen = word_length(string, delims);
        if (check_delim(*string, delims))
        {
            string = next_word(string, delims);
        }
        words[i] = malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
            {
                i--;
                free(words[i]);
            }
            free(words);
            return (NULL);
        }
        n = 0;
        while (n < wordLen)
        {
            words[i][n] = *(string + n);
            n++;
        }
        words[i][n] = '\0';
        string = next_word(string, delims);
        i++;
    }
    words[i] = NULL;
    return (words);
}


/**
 * check_delim - checks if stream has delimitor char
 *
 * @charaa: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */


int check_delim(char charaa, char *delims)
{
    int j = 0;


    for (j = 0; delims[j]; j++)
    {
        if (delims[j] == charaa)
            return (1);
    }
    return (0);
}


/**
 * word_length - calculate the lenght of words in a string 
 *
 * @string: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */


int word_length(char *string, char *delims)
{
    int wLen = 0, pend = 1, j = 0;


    while (*(string + j))
    {
        if (check_delim(string[j], delims))
            pend = 1;
        else if (pend)
        {
            wLen++;
        }
        if (wLen > 0 && check_delim(string[j], delims))
            break;
        j++;
    }
    return (wLen);
}
