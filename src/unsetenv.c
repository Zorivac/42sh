/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** .c
*/

#include "function.h"

void delete_ligne(int check, data_t *data)
{
    for (; data->cpy_env[check + 1] != NULL; check++)
        data->cpy_env[check] = data->cpy_env[check + 1];
    data->cpy_env[check] = NULL;
}

int check_unsetenv(char **array, data_t *data)
{
    int check = 0;

    if (my_strcmp(array[0], "unsetenv") == 0 &&
    (array_len(array) != 1)) {
        for (int i = 1; array[i] != NULL; i++) {
            check = check_arg(array, data, i);
            if (check >= 0)
                delete_ligne(check, data);
        }
    } else if (my_strcmp(array[0], "unsetenv") == 0 &&
    (array_len(array) == 1)) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return (ERROR);
    }
    return (VALID);
}
