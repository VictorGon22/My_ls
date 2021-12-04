/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

struct node *firstNode;

void createLinkedList(int numberOfNodes)
{
    struct node *newNode;
    struct node *currentNodes;
    int nodeData;
    int nodeCtr;
    firstNode = (struct node *) malloc(sizeof(struct node));
    if (firstNode == NULL) {
        printf("memory cant be allocated");
    } else {
        printf("input num:  ");
        scanf("%d", &nodeData);

        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;
        currentNodes = firstNode;

        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++) {
            
            newNode = (struct node *)malloc(sizeof(struct node));
            
            if (newNode == NULL) {
                printf("Memory can not be allocated");
                exit (84);
            } else {
                scanf("%d", &nodeData);
                newNode->data = nodeData;
                newNode->nextPtr = NULL;
                currentNodes->nextPtr = newNode;
                currentNodes = currentNodes->nextPtr;
            } 
        }
    }
}

void sortLinkedList (int numberOfNodes)
{
    int nodeCtr;
    int ctr;
    int nodeDataCopy;
    struct node *currentNode;
    struct node *nextNode;
    printf("nbr of nodes: %d\n", numberOfNodes);
    for (nodeCtr = numberOfNodes - 2; nodeCtr >= 0; nodeCtr--) {
        currentNode = firstNode;
        nextNode = currentNode->nextPtr;
        for (ctr = 0; ctr <= nodeCtr; ctr++) {
            if (currentNode->data > nextNode->data) {
                printf("esmes gran\n");
                nodeDataCopy = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = nodeDataCopy;
            }
            currentNode = nextNode;
            nextNode = nextNode->nextPtr;
        }
    }
}

void displayLinkedList()
{
    struct node *currentNode;
    currentNode = firstNode;
    while (currentNode != NULL)
    {
        printf("%d\t", currentNode->data);
        currentNode = currentNode->nextPtr;
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