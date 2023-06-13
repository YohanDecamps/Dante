/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-yohan.decamps
** File description:
** trace_path
*/

#include "my.h"

int get_random_adjacent_cell(maze_t* maze, int x, int y)
{
    int adjacent_cell[4];
    int count = 0;

    if (is_not_visited(maze, x - 2, y)) {
        adjacent_cell[count] = 0;
        count++;
    } if (is_not_visited(maze, x + 2, y)) {
        adjacent_cell[count] = 1;
        count++;
    } if (is_not_visited(maze, x, y - 2)) {
        adjacent_cell[count] = 2;
        count++;
    } if (is_not_visited(maze, x, y + 2)) {
        adjacent_cell[count] = 3;
        count++;
    } if (count > 0) {
        return adjacent_cell[rand() % count];
    }
    return -1;
}

maze_t* break_maze_wall(maze_t* maze, int x, int y, int direction)
{
    maze->grid[y * maze->width + x] = 0;
    if (direction == 0) {
        maze->grid[y * maze->width + x - 1] = 0;
        maze->grid[y * maze->width + x - 2] = 0;
    } if (direction == 1) {
        maze->grid[y * maze->width + x + 1] = 0;
        maze->grid[y * maze->width + x + 2] = 0;
    } if (direction == 2) {
        maze->grid[(y - 1) * maze->width + x] = 0;
        maze->grid[(y - 2) * maze->width + x] = 0;
    } if (direction == 3) {
        maze->grid[(y + 1) * maze->width + x] = 0;
        maze->grid[(y + 2) * maze->width + x] = 0;
    }
    return maze;
}

static coords_t store_path(coords_t* path, int adjacent_cell, int size)
{
    if (adjacent_cell == 0)
        return (coords_t) {path[size - 1].x - 2, path[size - 1].y
        };
    if (adjacent_cell == 1)
        return (coords_t) {path[size - 1].x + 2, path[size - 1].y
        };
    if (adjacent_cell == 2)
        return (coords_t) {path[size - 1].x, path[size - 1].y - 2
        };
    if (adjacent_cell == 3)
        return (coords_t) {path[size - 1].x, path[size - 1].y + 2
        };
    return (coords_t) {0, 0
    };
}

maze_t* generate_maze(maze_t* maze, int startX, int startY)
{
    coords_t* path = (coords_t*)
    malloc(maze->width * maze->height * sizeof(coords_t));
    int size = 0;
    int adjacent_cell = 0;
    path[size++] = (coords_t) {startX, startY};

    while (size > 0) {
        adjacent_cell = get_random_adjacent_cell
        (maze, path[size - 1].x, path[size - 1].y);
        if (adjacent_cell != -1) {
            maze = break_maze_wall(maze, path[size - 1].x,
            path[size - 1].y, adjacent_cell);
            path[size] = store_path(path, adjacent_cell, size);
            size++;
        } else
            size--;
    }
    free(path);
    return maze;
}
