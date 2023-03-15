#include <stdlib.h>
#include "main.h"

/**
 * count_words - counts the number of words in a string
 * @s: the string to count words in
 *
 * Return: the number of words in the string
 */
int count_words(char *s)
{
    int num_words = 0;
    int in_word = 0;
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
            in_word = 0;
        else if (in_word == 0)
        {
            num_words++;
            in_word = 1;
        }
    }

    return (num_words);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return (NULL);

    int num_words = count_words(str);
    if (num_words == 0)
        return (NULL);

    char **words;
    int word_idx = 0;
    int word_start = 0;
    int word_len = 0;
    int i, j;

    words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            if (word_len > 0)
            {
                char *new_word = malloc((word_len + 1) * sizeof(char));
                if (new_word == NULL)
                {
                    for (j = 0; j < word_idx; j++)
                        free(words[j]);
                    free(words);
                    return (NULL);
                }

                for (j = 0; j < word_len; j++)
                    new_word[j] = str[word_start + j];

                new_word[word_len] = '\0';
                words[word_idx] = new_word;
                word_idx++;
                word_len = 0;
            }

            word_start = i + 1;
        }
        else
            word_len++;
    }

    if (word_len > 0)
    {
        char *new_word = malloc((word_len + 1) * sizeof(char));
        if (new_word == NULL)
        {
            for (j = 0; j < word_idx; j++)
                free(words[j]);
            free(words);
            return (NULL);
        }

        for (j = 0; j < word_len; j++)
            new_word[j] = str

