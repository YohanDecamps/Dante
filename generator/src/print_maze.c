/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-yohan.decamps
** File description:
** print_maze
*/

#include "my.h"

void print_condition(maze_t* maze, int i, int j)
{
    if (maze->width % 2 == 0 && maze->height % 2 == 0) {
        if (i + 1 == maze->height && j + 1 == maze->width) {
            printf("*");
            return;
        } if (i + 2 == maze->height && j + 1 == maze->width) {
            printf("*");
            return;
        }
    } if (maze->width % 2 == 0 || maze->height % 2 == 0)
        if (i + 1 == maze->height && j + 1 == maze->width) {
            printf("*");
            return;
        }
    if (maze->grid[i * maze->width + j] == 1) {
        printf("X");
    } else {
        printf("*");
    }
}

void print_maze(maze_t* maze)
{
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            print_condition(maze, i, j);
        }
        if (maze->height - 1 != i)
            printf("\n");
    }
}
