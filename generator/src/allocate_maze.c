/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-yohan.decamps
** File description:
** allocate_maze
*/

#include "my.h"

maze_t* allocate_maze(const int argc, const char **argv)
{
    if (argc < 3 || argc > 4)
        return NULL;
    maze_t* maze = malloc(sizeof(maze_t));
    maze->perfect = 0;
    if (argc == 4) {
        if (!strcmp(argv[3], "perfect"))
            maze->perfect = 1;
        else
            return NULL;
    }
    maze->width = atoi(argv[1]);
    maze->height = atoi(argv[2]);
    if (maze->width <= 0 || maze->height <= 0) return NULL;
    maze->grid = malloc(sizeof(int) * maze->width * maze->height);
    for (int i = 0; i < maze->width * maze->height; i++)
        maze->grid[i] = 1;
    return maze;
}

void free_maze(maze_t* maze)
{
    free(maze->grid);
    free(maze);
}
