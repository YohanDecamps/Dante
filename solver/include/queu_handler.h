/*
** EPITECH PROJECT, 2023
** dante
** File description:
** queu_handler
*/

#ifndef QUEU_HANDLER_H_
    #define QUEU_HANDLER_H_

    #include "struct.h"

queu_t *add_to_queu (coord_t coo, queu_t *head, queu_t *prev);
queu_t * get_next_visit(queu_t *queu, char **maze, int x_lim, int y_lim);
queu_t * next_in_queu(queu_t * queu);

#endif /* !QUEU_HANDLER_H_ */
