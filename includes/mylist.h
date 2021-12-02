/*
** EPITECH PROJECT, 2021
** mylist.h
** File description:
** 
*/

#ifndef MYLIST_H
#define MYLIST_H_

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;


linked_list_t *my_params_to_list(int ac, char * const *av);


#endif /* MYLIST_H */