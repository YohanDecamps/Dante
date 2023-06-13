/*
** EPITECH PROJECT, 2023
** dante
** File description:
** printer
*/

#include "include.h"
#include "utils.h"
#include "struct.h"

static void print_maze (char **maze)
{
    int i = -1;
    while (maze[++i]) {
        printf("%s", maze[i]);
        if (maze[i + 1] != NULL)
            printf("\n");
    }
}

static void clear_line_for_print (char *line)
{
    int i = -1;
    while (line[++i]) {
        if (line[i] == ' ')
            line[i] = '*';
    }
}

static void clear_maze_for_print (char **maze)
{
    int i = -1;
    while (maze[++i])
        clear_line_for_print(maze[i]);
}

void print_soluce (queu_t *solution, char **maze)
{
    int i = -1;
    int x = 0;
    int y = 0;
    if (solution == NULL)
        return;
    maze[y][x] = 'o';
    while (solution != NULL) {
        maze[solution->coord.y][solution->coord.x] = 'o';
        solution = solution->prev;
    }
    clear_maze_for_print(maze);
    print_maze(maze);
}
