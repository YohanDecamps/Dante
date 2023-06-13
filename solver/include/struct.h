/*
** EPITECH PROJECT, 2023
** dante
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct queu_s {
    coord_t coord;
    struct queu_s *prev;
    struct queu_s *next;
} queu_t;

#endif /* !STRUCT_H_ */
