/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

int error_num_elements (int num_flags, int num_directories, int argc)
{
    if (num_flags < 1 || num_directories < 1 || argc < 3) {
        //printf("%d\n", num_flags);
        //printf("%d\n", num_directories);
        //printf("%d\n", argc);
        return (1);
    }
    return (0);
}

int error_flags (char *flags)
{
    int i = 0;
    int j = 0;
    int inbase = 0;
    char base[] = "adFilahrRsStX";

    while (flags[i] != '\0') {
        j = 0;
        while (base[j] != '\0') {
            if (base[j]  == flags[i])
                inbase = 1;
            j++;
        }
        i++;
        if (inbase == 0)
            return (1);
        inbase = 0;
    }
    return (0);
}

int error_directories (char *dir)
{
    int i = 0;
    DIR *dp;
    struct stat fileStat;
    dp = opendir(dir);
    if (dp == NULL && stat(dir, &fileStat))
        return (1);
    i++;
    return (0);
}

void errormanager_general (t_var *var)
{
    if (error_flags (var->array_flags) || error_num_elements(var->flags, var->directories, var->argc)) {
        printf("ERROR");
        exit (84);
    }
}

void errormanager_directories (char *filepath)
{
    if (error_directories (filepath)) {
        printf("ERROR2");
        exit (84);
    }
}