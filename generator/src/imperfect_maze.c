/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-yohan.decamps
** File description:
** imperfect_maze
*/

#include "my.h"

maze_t *imperfect_maze(maze_t *maze)
{
    for (int i = 0; i < maze->height * maze->width; i++) {
        if (maze->grid[i] == 1 && rand() % 5 == 1)
            maze->grid[i] = 0;
    }
    return (maze);
}
