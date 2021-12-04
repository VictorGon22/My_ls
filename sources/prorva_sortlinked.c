/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

t_info_files *firstNode;

void createLinkedList(int numberOfNodes)
{
    t_info_files *newNode;
    t_info_files *currentNodes;
    int nodeData;
    int nodeCtr;

    firstNode = (t_info_files *) malloc(sizeof(t_info_files));
    if (firstNode == NULL) {
        printf("memory cant be allocated");
    } else {
        printf("input num:  ");
        scanf("%d", &nodeData);

        firstNode->filesize = nodeData;
        firstNode->next = NULL;
        currentNodes = firstNode;
        
        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++) {
            newNode = (t_info_files *) malloc(sizeof(t_info_files));
            if (newNode == NULL) {
                printf("Memory can not be allocated");
                exit (84);
            } else {
                scanf("%d", &nodeData);
                newNode->filesize = nodeData;
                newNode->next = NULL;
                currentNodes->next = newNode;
                currentNodes = currentNodes->next;
            } 
        }
    }
}

void sortLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int ctr;
    int nodeDataCopy;
    t_info_files *currentNode;
    t_info_files *nextNode;
    
    for (nodeCtr = numberOfNodes - 2; nodeCtr >= 0; nodeCtr--) {
        currentNode = firstNode;
        nextNode = currentNode->next;
        for (ctr = 0; ctr <= nodeCtr; ctr++) {
            if (currentNode->filesize > nextNode->filesize) {
                nodeDataCopy = currentNode->filesize;
                currentNode->filesize = nextNode->filesize;
                nextNode->filesize = nodeDataCopy;
            }
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
    }
}

void displayLinkedList()
{
    t_info_files *currentNode;
    currentNode = firstNode;
    while (currentNode != NULL)
    {
        printf("%d\t", currentNode->filesize);
        currentNode = currentNode->next;
    }
}

int main()
{
    int numberOfNodes;
    firstNode = NULL;
    printf("Input the numbner of elemnts in the linked list:");
    scanf("%d", &numberOfNodes);
    createLinkedList(numberOfNodes);
    sortLinkedList(numberOfNodes);
    printf("Sorted order is: \n");
    displayLinkedList();
    return (0);

}