/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void save_flags_dir (t_var *var, int i, char **argv)
{
    int  j = 1;

    if (argv[i][0] == '-'){
            j = 1;
            while (argv[i][j] != '\0') {
                var->array_flags[var->flags] = argv[i][j];
                var->flags ++;
                j++;
            }
        } 
        else {
             var->array_directory[var->directories] = argv[i];
             var->directories ++;
        }
}

void my_ls(int argc, char **argv)
{
    t_var var;

    int i = 1;
    int j = 1;
    var.flags = 0;
    var.directories = 0;
    var.argc = argc;
    
    while (argv[i] != NULL) {
        save_flags_dir (&var, i, argv);
        i++;
    }
    errormanager_general(&var);
}

int main (int argc, char **argv)
{
    my_ls(argc, argv);
    return (0);
}