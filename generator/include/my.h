/*
** EPITECH PROJECT, 2023
** dante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>

    #define ERROR 84
    #define SUCCESS 0
    #define FAILURE 1

    typedef struct coords_s {
        int x;
        int y;
    } coords_t;

    typedef struct maze_s {
        int* grid;
        int width;
        int height;
        int perfect;
    } maze_t;

    void free_maze(maze_t* maze);

    maze_t* allocate_maze(const int argc, const char **argv);

    int is_visited(maze_t* maze, int x, int y);

    int is_not_visited(maze_t* maze, int x, int y);

    int is_cell_inside(maze_t* maze, int x, int y);

    int get_random_adjacent_cell(maze_t* maze, int x, int y);

    maze_t* break_maze_wall(maze_t* maze, int x, int y, int direction);

    maze_t* generate_maze(maze_t* maze, int startX, int startY);

    void print_maze(maze_t* maze);

    maze_t *imperfect_maze(maze_t *maze);

#endif
