/*
** EPITECH PROJECT, 2/*
** EPITECH PROJECT, 2021
** Sebas-i-victor-printf
** File description:
** myls.h
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

t_info_files save_info (t_info_files file)
{
    t_info_files temp;

    temp.name = file.name;
    temp.permisions = file.permisions;
    temp.date = file.date;
    temp.owner = file.owner;
    temp.group = file.group;
    temp.filesize = file.filesize;
    temp.linkcount = file.linkcount;
    return (temp);
}

t_info_files *sort_file_size_notreversed(t_info_files *list, int len, int i)
{
    int j = i;
    t_info_files temp;

    while (j < len) {
        if (list[i].filesize > list[j].filesize) {
            temp = save_info (list[i]);
            list[i] = save_info(list[j]);
            list[j] = save_info(temp);
        }
        j++;
    }
    return list;
}
