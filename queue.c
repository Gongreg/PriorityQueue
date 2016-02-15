#include <stdlib.h>
#include "queue.h"
#include "queue_codes.h"

int initQueue(Queue** queue)
{
    *queue = (Queue*) calloc(1, sizeof(Queue));
    if (*queue == NULL) {
        return QUEUE_NOT_CREATED;
    }

    return 0;
}

int destroyQueue(Queue** queue)
{
    if (*queue == NULL) {
        return QUEUE_DESTROYED;
    }

    Node* node = (*queue)->first;

     if ((*queue)->length > 0) {
        while (node != NULL && node->next != NULL) {
            node = node->next;
            free(node->previous);
        }

        free((*queue)->last);
     }

    //free queue memory
    free(*queue);
    //set queue pointer to null
    *queue = NULL;

    return 0;
}

//Remove first element from queue
int popQueue(Queue* queue)
{
    if (queue == NULL) {
        return QUEUE_NOT_CREATED;
    }

    if (queue->length == 0) {
        return QUEUE_EMPTY;
    }

    Node* node = queue->first;

    if (node == NULL) {
        return ELEMENT_EMPTY;
    }

    //only one element in queue
    if (node->next == NULL) {
        queue->first = NULL;
        queue->last = NULL;
    } else {
         node->next->previous = NULL;
         queue->first = node->next;
    }

    queue->length -= 1;

    free(node);
    return 0;
}

int pushQueue(Queue* queue, int value, int priority) {
    if (queue == NULL) {
        return QUEUE_NOT_CREATED;
    }

    Node* node = (Node*) calloc(1, sizeof(Node));

    if (node == NULL) {
        return ELEMENT_EMPTY;
    }

    node->value = value;
    node->priority = priority;

    //if nothing is in queue,
    if (queue->first == NULL) {
        queue->first = node;
        queue->last = node;
    } else {
        Node* temp = queue->last;
        int set = 0;
        while (temp != NULL) {
            if (temp->priority >= node->priority) {
                node->previous = temp->previous;
                node->next = temp;

                if (temp->previous) {
                    temp->previous->next = node;
                } else {
                    queue->first = node;
                }

                temp->previous = node;

                set = 1;
                break;
            }
        }

        if (!set) {
            node->previous = queue->last;
            queue->last = node;
        }
    }

    queue->length += 1;

    return 0;
}

// Check if queue is empty (not created or no elements inside it)
int isEmptyQueue(Queue* queue) {
    return queue == NULL || queue->length == 0;
}
