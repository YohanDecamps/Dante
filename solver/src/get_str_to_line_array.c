/*
** EPITECH PROJECT, 2023
** dante
** File description:
** my_str_to_line_array
*/

#include "include.h"
#include "utils.h"

static int get_line_len (const char *str)
{
    int i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return i;
}

static int count_line (const char *str)
{
    int c = 1;
    int i = -1;
    int nbw = 0;
    while (str[++i]) {
        if (c && str[i] != '\n') {
            nbw++;
            c = 0;
        }
        if (str[i] == '\n')
            c = 1;
    }
    return (nbw);
}

static void separate_words (char const *str, char **word_l)
{
    int i = -1;
    int j = 0;
    int y = 0;
    while (str[++i]) {
        if (str[i] != '\n') {
            word_l[y][j] = str[i];
            j++;
        }
        if (str[i] == '\n') {
            y++;
            j = 0;
        }
    }
}

char **get_str_to_line_array (char * str)
{
    int line_nb = count_line(str);
    int line_len = get_line_len(str);
    int i = -1;
    char **word_l = malloc(sizeof(char*) * (line_nb + 1));
    word_l[line_nb] = NULL;
    while (++i < line_nb) {
        word_l[i] = malloc(sizeof(char) * (line_len + 1));
        word_l[i][line_len] = '\0';
    }
    separate_words (str, word_l);
    free(str);
    if (word_l[line_nb - 1][line_len - 1] == '*')
        word_l[line_nb - 1][line_len - 1] = '0';
    return word_l;
}
