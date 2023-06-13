/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-yohan.decamps
** File description:
** check_inside_cell
*/

#include "my.h"

int is_cell_inside(maze_t* maze, int x, int y)
{
    if (x >= 0 && x < maze->width && y >= 0 && y < maze->height)
        return 1;
    return 0;
}

int is_not_visited(maze_t* maze, int x, int y)
{
    if (is_cell_inside(maze, x, y) && maze->grid[y * maze->width + x] == 1)
        return 1;
    return 0;
}

int is_visited(maze_t* maze, int x, int y)
{
    if (is_cell_inside(maze, x, y) && maze->grid[y * maze->width + x] == 0)
        return 1;
    return 0;
}
