/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

t_info_1_file *save_info(t_info_files *file)
{
    t_info_1_file *tmp = (t_info_1_file *) malloc(sizeof(t_info_1_file));

    tmp->name = file->name;
    tmp->permisions = file->permisions;
    tmp->date = file->date;
    tmp->owner = file->owner;
    tmp->group = file->group;
    tmp->filesize = file->filesize;
    tmp->linkcount = file->linkcount;
    return (tmp);
}

t_info_files *change_info(t_info_1_file *file)
{
    t_info_files *tmp = (t_info_files *) malloc(sizeof(t_info_files));

    tmp->name = file->name;
    tmp->permisions = file->permisions;
    tmp->date = file->date;
    tmp->owner = file->owner;
    tmp->group = file->group;
    tmp->filesize = file->filesize;
    tmp->linkcount = file->linkcount;
    return (tmp);
}
t_info_files *sortSize(int numberOfNodes, t_info_files *firstNode, int reverse)
{
    int nodeCtr;
    int ctr;
    int nodeDataCopy;
    t_info_files *currentNode;
    t_info_files *nextNode;
    t_info_1_file *tmp = (t_info_1_file *) malloc(sizeof(t_info_1_file));
    t_info_1_file *tmp2= (t_info_1_file *) malloc(sizeof(t_info_1_file));

    printf("%d\n", numberOfNodes);
    for (nodeCtr = numberOfNodes - 2; nodeCtr >= 0; nodeCtr--) {
        currentNode = firstNode;
        nextNode = currentNode->next;

        if (reverse == 1) {
            for (ctr = 0; ctr <= nodeCtr; ctr++) {
                
                if (currentNode->filesize > nextNode->filesize) {
                    tmp = save_info(currentNode);
                    tmp2 = save_info(nextNode);
                    currentNode = change_info(tmp2);
                    currentNode = currentNode->next;
                    currentNode = change_info(tmp);
                    printf("ENTRa");
                    //firstNode->name = "ENTRA";
                    //printf("size: %s\n", firstNode->name);
                    //currentNode->filesize = nextNode->filesize;
                    //nextNode->filesize = nodeDataCopy;
                    //currentNode = nextNode;
                }
                
                //else
                  //  
                currentNode = nextNode;
                nextNode = nextNode->next;
            }

        }
        
    }
    return (currentNode);
}






















/*
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
*//*
void sort_file_name_reversed(t_info_files *list, int i, int len)
{
    int j = i;
    int k  = 0;
    t_info_files *tmp;
    //t_info_files *file = list;
    //file = file->next;
    printf("ENTRA\n");
    while (list->next != NULL) {
        k = 0;
        while(list->data->name[k] == list->next->data->name[k] && list->data->name[k] != '\0')
            k++;
        if (list->data->name[k] < list->next->data->name[k]) {
            //save_info(list, tmp);
            //save_info(list->next, list);
            //save_info(tmp, list->next);
        }
        list = list->next;
    }
    //return file;
}*/
/*
void sort_file_name_notreversed(t_info_files *list, int i, int len)
{
    int j = i;
    int k  = 0;
    t_info_files *temp;// = malloc(sizeof(t_info_files));

    while (list->next != NULL) {
        k = 0;
        while(list->name[k] == list->next->name[k] && list->name[k] != '\0')
            k++;
        if (list->name[k] > list->next->name[k]) {
            temp = save_info(list);
            list = save_info(list->next);
            list->next = save_info(temp);
        }
        list = list->next;
    }
    //return list;
}
*//*
void sort_file_name(t_info_files *list, int reverse, int len)
{
    int i = 0;

    //int len = sizeof(*list) / sizeof(t_info_files);
    printf("len %d\n", len);
    
    while (i < len)
    {
        //if (reverse == 1)
        //    sort_file_name_notreversed(list, i, len);
        //else
        sort_file_name_reversed(list, i, len);
        i++;
    }
    //return list;
}
*/