/*
** EPITECH PROJECT, 2026
** my_str_to_word_array
** File description:
** Put each words of a string into an array
*/

#include "../include/my.h"

int is_delimiter(char c, char *delimiter)
{
    int i = 0;

    while (delimiter[i] != '\0') {
        if (c == delimiter[i])
            return 1;
        i++;
    }
    return 0;
}

int word_length(char const *str, int i, char *delimiter)
{
    int len = 0;

    while (str[i] != '\0' && !is_delimiter(str[i], delimiter)) {
        len++;
        i++;
    }
    return len;
}

int find_word(char const *str, char *delimiter)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && is_delimiter(str[i], delimiter))
            i++;
        if (str[i] == '\0')
            break;
        nb++;
        while (str[i] != '\0' && !is_delimiter(str[i], delimiter))
            i++;
    }
    return nb;
}

char *extract_word(char const *str, int *i, char *delimiter)
{
    int len = word_length(str, *i, delimiter);
    char *word = malloc(sizeof(char) * (len + 1));
    int k = 0;

    while (k < len) {
        word[k] = str[*i];
        k++;
        (*i)++;
    }
    word[k] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str, char *delimiter)
{
    int nb = find_word(str, delimiter);
    char **array = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int key = 0;

    while (key < nb) {
        while (str[i] != '\0' && is_delimiter(str[i], delimiter))
            i++;
        array[key] = extract_word(str, &i, delimiter);
        key++;
    }
    array[key] = NULL;
    return array;
}
