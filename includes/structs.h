/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct s_var 
{
    char *name;
    char *permisions;
    char *date;
    char *owner;
    char *group;
    int filesize;
    int linkcount;
    char array_flags[5];
    char *array_directory[5];
    char **args;
    int argc;
    int flags;
    int directories;
    
} t_var;

typedef struct s_info_files 
{
    char *name;
    char *permisions;
    char *date;
    char *owner;
    char *group;
    int filesize;
    int linkcount;
    struct s_info_files *previous;
    struct s_info_files *next;

} t_info_files;

typedef struct do_op
{
    char op;
    void (*ptr)(va_list list);
} calculator;

#endif

