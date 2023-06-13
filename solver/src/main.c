/*
** EPITECH PROJECT, 2023
** stumper02
** File description:
** main
*/

#include "solver.h"

int main (int argc, char ** argv)
{
    if (argc != 2)
        return 84;
    return maze_solver(argv[1]);
}
