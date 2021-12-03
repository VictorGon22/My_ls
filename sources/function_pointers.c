/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"
/*
void fill_flags2(calculator *flags)
{
    flags[8].op = 'r';
    flags[8].ptr = &func_r;
    flags[9].op = 'R';
    flags[9].ptr = &func_R;
    flags[10].op = 's';
    flags[10].ptr = &func_s;
    flags[11].op = 'S';
    flags[11].ptr = &func_S;
    flags[12].op = 't';
    flags[12].ptr = &func_t;
    flags[13].op = 'X';
    flags[13].ptr = &func_X;
}*/


void fill_flags(calculator *flags)
{
    flags[0].op = 'l';
    flags[0].ptr = &func_l;
    /*flags[1].op = '-d';
    flags[1].ptr = &func_d;
    flags[2].op = '-F';
    flags[2].ptr = &func_F;
    flags[3].op = '-i';
    flags[3].ptr = &func_i;
    flags[4].op = '-l';
    flags[4].ptr = &func_l;
    flags[5].op = '-la';
    flags[5].ptr = &func_la;
    flags[6].op = '-lh';
    flags[6].ptr = &func_lh;
    flags[7].op = '-ls';
    flags[7].ptr = &func_ls;
    fill_flags2(flags);*/
}

int func_pointer(char *filepath, char type)
{
    int i = 0;
    calculator flags[1];

    fill_flags(flags);
    while (i < 1) {
        if (type == flags[i].op)
            (*(flags[i].ptr))(filepath);
        i++;
    }
    return (0);
}
