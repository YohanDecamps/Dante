/*
** EPITECH PROJECT, 2023
** dante
** File description:
** maze_resolution
*/

#include "include.h"
#include "struct.h"
#include "queu_handler.h"
#include "utils.h"
#include "get.h"
#include "printer.h"

static queu_t *resolve_maze (char **maze)
{
    queu_t *queu = add_to_queu((coord_t) {0, 0}, NULL, NULL);
    int x_lim = strlen(maze[0]);
    int y_lim = my_str_str_len(maze);
    while (queu) {
        if (maze[queu->coord.y][queu->coord.x] == '0') {
            maze[queu->coord.y][queu->coord.x] = ' ';
            return queu;
        }
        if (maze[queu->coord.y][queu->coord.x] != '*') {
            queu = next_in_queu(queu);
            continue;
        }
        maze[queu->coord.y][queu->coord.x] = ' ';
        queu = get_next_visit(queu, maze, x_lim, y_lim);
    }
    return NULL;
}

int maze_solver (char *path)
{
    char **maze = get_maze(path);
    if (maze == NULL)
        return 84;
    queu_t *solution = resolve_maze(maze);
    if (solution == NULL) {
        printf("no solution found");
        return 84;
    }
    print_soluce(solution, maze);
    free_maze(maze);
}
