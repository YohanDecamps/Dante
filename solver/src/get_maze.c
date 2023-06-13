/*
** EPITECH PROJECT, 2023
** dante
** File description:
** get_maze
*/

#include "include.h"
#include "get.h"

int maze_is_valid (const char *buffer)
{
    int i = -1;
    while (buffer[++i]) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n')
            return 0;
    }
    if (buffer[i - 1] == '\n')
        return 0;
    return 1;
}

char **get_maze (const char *filename)
{
    FILE *fp;
    char *buffer;
    struct stat s;
    if (stat(filename, &s) != 0) return NULL;
    if ((fp = fopen (filename, "rd")) == NULL)
        return NULL;
    buffer = malloc((s.st_size + 1) * sizeof(char));
    if (fread(buffer, s.st_size, 1, fp) != 1) {
        fclose(fp);
        free(buffer);
        return NULL;
    }
    buffer[s.st_size] = '\0';
    fclose(fp);
    if (!maze_is_valid(buffer)) {
        free(buffer);
        return NULL;
    }
    buffer[s.st_size] = '\0';
    return get_str_to_line_array(buffer);
}
