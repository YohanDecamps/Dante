/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-yohan.decamps
** File description:
** main
*/

#include "my.h"

int main(const int argc, const char **argv)
{
    srand(time(NULL));
    maze_t* maze = allocate_maze(argc, argv);
    if (maze == NULL)
        return ERROR;
    maze = generate_maze(maze, 0, 0);
    if (!maze->perfect)
    maze = imperfect_maze(maze);
    print_maze(maze);
    free_maze(maze);
    return SUCCESS;
}
