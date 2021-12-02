/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

t_info_files *sort_file_size_reversed(t_info_files *list, int len, int i)
{
    int j = i;
    t_info_files temp;

    while (j < len) {
        if (list[i].filesize < list[j].filesize) {
            temp = save_info (list[i]);
            list[i] = save_info(list[j]);
            list[j] = save_info(temp);
        }
        j++;
    }
    return list;
}

t_info_files *sort_file_size(t_info_files *list, int reverse)
{
    int i = 0;
    int len = sizeof(*list) / sizeof(t_info_files);

    while (i < len)
    {
        if (reverse == 1)
            sort_file_size_notreversed(list, len, i);
        else
            sort_file_size_reversed(list, len, i);
        
        i++;
    }
    return (list);
}

t_info_files *sort_file_name_reversed(t_info_files *list, int i, int len)
{
    int j = i;
    int k  = 0;
    t_info_files temp;

    while (j < len) {
        k = 0;
        while(list->name[k] == list->next->name[k] && list->name[k] != '\0')
            k++;
        if (list->name[k] < list->next->name[k]) {
            temp = save_info (list[i]);
            list[i] = save_info(list[j]);
            list[j] = save_info(temp);
        }
        j++;
    }
    return list;
}

t_info_files *sort_file_name_notreversed(t_info_files *list, int i, int len)
{
    int j = i;
    int k  = 0;
    t_info_files temp;

    while (j < len) {
        k = 0;
        while(list->name[k] == list->next->name[k] && list->name[k] != '\0')
            k++;
        if (list->name[k] > list->next->name[k]) {
            temp = save_info (list[i]);
            list[i] = save_info(list[j]);
            list[j] = save_info(temp);
        }
        j++;
    }
    return list;
}

t_info_files *sort_file_name(t_info_files *list, int reverse)
{
    int i = 0;
    int len = sizeof(*list) / sizeof(t_info_files);

    while (i < len)
    {
        if (reverse == 1)
            list = sort_file_name_notreversed(list, i, len);
        else
            list = sort_file_name_reversed(list, i, len);
        i++;
    }
    return list;
}
