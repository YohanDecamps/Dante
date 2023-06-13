/*
** EPITECH PROJECT, 2023
** dante
** File description:
** utils
*/

#include "include.h"

int my_str_str_len (char **str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    while (str[i])
        i++;
    return i;
}

void free_maze (char **maze)
{
    int i = -1;
    if (maze == NULL)
        return;
    while (maze[++i])
        free(maze[i]);
    free(maze);
}
