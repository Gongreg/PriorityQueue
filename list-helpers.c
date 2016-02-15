#include <stdlib.h>
#include <stdio.h>
#include "14uzd.h"

const int LIST_NOT_CREATED = 1;
const int LIST_EMPTY = 2;
const int ELEMENT_EMPTY = 3;

List* createList()
{
    List* list = (List*) calloc(1, sizeof(List));
    if (list == NULL) {
        printf("Nepavyko sąrašui priskirti atminties\n!");
        return LIST_NOT_CREATED;
    }

    return list;
}

int push(List* list, Data value)
{
    if (list == NULL) {
        printf("Sąrašas neegzistuoja, iš pradžių sukurkite!\n!");
        return LIST_NOT_CREATED;
    }

    Node* node = (Node*) calloc(1, sizeof(Node));

    if (node == NULL) {
        printf("Nepavyko elementui priskirti atminties\n!");
        return ELEMENT_EMPTY;
    }

    node->value = value;

    if (list->first == NULL) {
        list->first = node;
    } else {
        //point previous element to new one
        node->previous = list->last;
        list->last->next = node;
    }

    list->last = node;
}

int removeLowest(List* list)
{
    int removeNodeResult;
    if (list == NULL || list->first == NULL) {
        printf("Sąrašas tuščias, pirmiau inicijuokite prieš šąlinant \n");
        return LIST_NOT_CREATED;
    }

    Node *node = list->first;
    Node *minNode = node;
    Data value;

    while (node != NULL) {
        if (node->value < minNode->value) {
            minNode = node;
        }
        node = node->next;
    }

    value = minNode->value;


    removeNodeResult = removeNode(list, minNode);

    if (removeNodeResult) {
        return removeNodeResult;
    }

    printf("Pašalinta reikšmė: %d\n", minNode->value);
    return 0;
}

int removeNode(List* list, Node* node)
{
    if (list == NULL) {
        printf("Negalima pašalinti elemento, sąrašas nesukurtas!\n");
        return LIST_NOT_CREATED;
    }

    if (list->first == NULL) {
        printf("Negalima pašalinti elemento, sąrašas tuščias!\n");
        return LIST_EMPTY;
    }

    if (node == NULL) {
        printf("Elementas tuščias!\n");
        return ELEMENT_EMPTY;
    }

    //only one element in list
    if (node->previous == NULL && node->next == NULL) {
        list->first = NULL;
        list->last = NULL;
    } else if (node->next == NULL) {
         //last element
         node->previous->next = NULL;
         list->last = node->previous;
    } else if (node->previous == NULL) {
         //first element
         node->next->previous = NULL;
         list->first = node->next;
     } else {
         //somewhere in the middle
         node->previous->next = node->next;
         node->next->previous = node->previous;
     }

    free(node);
    return 0;
}

void mapList(List* list)
{
    if (list == NULL || list->first == NULL) {
        printf("Sąrašas tuščias. \n");
        return;
    }

    Node* node = list->first;

    printf("Sąrašas: ");

    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }

    printf("\n");
}

int destroyList(List** list)
{
    if (*list == NULL) {
        printf("Sąrašas jau sunaikintas!\n");
        return LIST_EMPTY;
    }

    Node* node = (*list)->first;

    while (node != NULL && node->next != NULL) {
        node = node->next;
        free(node->previous);
    }

    free((*list)->last);
    free(*list);

    *list = NULL;

    return 0;
}
