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

void errormanager_general (t_var *var);
void errormanager_general (t_var *var);
char *my_strcat(char *dest, char const *src);
t_info_files *sort_file_size_reversed(t_info_files *list, int len, int i);
t_info_files *sort_file_size(t_info_files *list, int reverse);
t_info_files *sort_file_name_reversed(t_info_files *list, int i, int len);
t_info_files *sort_file_name_notreversed(t_info_files *list, int i, int len);
t_info_files *sort_file_name(t_info_files *list, int reverse);
t_info_files save_info (t_info_files file);
t_info_files *sort_file_size_notreversed(t_info_files *list, int len, int i);

#endif