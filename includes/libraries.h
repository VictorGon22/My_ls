/*
** EPITECH PROJECT, 2021
** Sebas-i-victor-printf
** File description:
** myls.h
*/

#ifndef LIBRARIES_H_
#define LIBRARIES_H_

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "./structs.h"

void errormanager_general(t_var *var);
void errormanager_directories(char *dir);
char *my_strcat(char *dest, char const *src);
int func_pointer(char *filepath, char type);
void func_l(char *filepath);
void func_d(char *filepath);
void func_w(char *filepath);
void sortLinkedList(int numberOfNodes, t_info_files *);


t_info_files *sort_file_size_reversed(t_info_files *list, int len, int i);
t_info_files *sort_file_size(t_info_files *list, int reverse);
void sort_file_name_reversed(t_info_files *list, int i, int len);
void sort_file_name_notreversed(t_info_files *list, int i, int len);
void sort_file_name(t_info_files *list, int reverse, int len);
void save_info (t_info_files *file, t_info_files *tmp);
t_info_files *sort_file_size_notreversed(t_info_files *list, int len, int i);

#endif