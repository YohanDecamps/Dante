/*
** EPITECH PROJECT, 2023
** dante
** File description:
** queu_handler
*/

#include "include.h"
#include "struct.h"
#include "utils.h"

static queu_t *get_new_queu (coord_t coord, queu_t *head, queu_t *prev)
{
    queu_t *current = head;
    queu_t *temp = NULL;
    while (current->next && current->next->coord.x +  current->next->coord.y
    >= coord.x + coord.y) current = current->next;
    if (current->next == NULL) {
        current->next = malloc(sizeof(queu_t));
        current->next->coord = coord;
        current->next->prev = prev;
        current->next->next = NULL;
        return head;
    }
    temp = malloc(sizeof(queu_t));
    temp->coord = coord;
    temp->next = current->next;
    temp->prev = prev;
    current->next = temp;
    return head;
}

static queu_t *complete_queu (coord_t coord, queu_t *head, queu_t *prev)
{
    queu_t *current = head;
    queu_t *temp = NULL;
    if ((current->coord.x) + (current->coord.y) < coord.x + coord.y) {
        temp = malloc(sizeof(queu_t));
        temp->coord.x = coord.x;
        temp->coord.y = coord.y;
        temp->next = head;
        temp->prev = prev;
        return temp;
    }
    return get_new_queu(coord, head, prev);
}

queu_t *add_to_queu (coord_t coo, queu_t *head, queu_t *prev)
{
    if (head == NULL) {
        head = malloc(sizeof(queu_t));
        head->next = NULL;
        head->coord = coo;
        head->prev = prev;
        return head;
    }
    return get_new_queu(coo, head, prev);
}

queu_t * get_next_visit(queu_t *queu, char **maze, int x_lim, int y_lim)
{
    int x = queu->coord.x; int y = queu->coord.y;

    queu_t *head = queu;
    if (queu == NULL)
        return NULL;
    if (y < 0 || x < 0)
        return queu;
    if (x > 0 && maze[y][x - 1] == '*')
        queu = add_to_queu((coord_t){x - 1, y}, queu, head);
    if (x < x_lim - 1 && (maze[y][x + 1] == '*' || maze[y][x + 1] == '0'))
        queu = add_to_queu((coord_t){x + 1, y}, queu, head);
    if (y > 0 && maze[y - 1][x] == '*')
        queu = add_to_queu((coord_t){x, y - 1}, queu, head);
    if (y < y_lim - 1 && (maze[y + 1][x] == '*' || maze[y + 1][x] == '0'))
        queu = add_to_queu((coord_t) {x, y + 1}, queu, head);
    return queu;
}

queu_t * next_in_queu(queu_t * queu)
{
    queu_t *new_queu = queu->next;
    if (queu == NULL)
        return NULL;
    return new_queu;
}
