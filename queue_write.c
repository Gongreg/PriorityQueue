#include <stdio.h>
#include "queue_write.h"
#include "queue_codes.h"
#include "queue.h"

void printMessage(int response) {
    if (response == 0) {
        return;
    }

    if (response == QUEUE_NOT_CREATED) {
        printf("Prioritetinė eilė nesukurta\n");
        return;
    }

    if (response == QUEUE_EMPTY) {
        printf("Prioritetinė eilė tuščia\n");
        return;
    }

    if (response == QUEUE_DESTROYED) {
        printf("Prioritetinė eilė jau sunaikinta\n");
        return;
    }

    if (response == ELEMENT_EMPTY) {
        printf("Elementas tuščias (nepavyko sukurti)\n");
        return;
    }

    printf("Nežinomas klaidos kodas\n");

}

void mapQueue(Queue* queue) {
    if (queue == NULL){
        printMessage(QUEUE_NOT_CREATED);
        return;
    }

    if (queue->first == NULL) {
        printMessage(QUEUE_EMPTY);
        return;
    }

    Node* node = queue->first;

    printf("Sąrašas:\n");

    while (node != NULL) {
        printf("prioritetas: %d, reiksme: %d \n", node->priority, node->value);
        node = node->next;
    }
}
