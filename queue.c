#include <stdlib.h>
#include "queue.h"
#include "queue_codes.h"

int initQueue(Queue** queue)
{
    *queue = (Queue*) calloc(1, sizeof(Queue));
    if (*queue == NULL) {
        return QUEUE_NOT_CREATED;
    }

    (*queue)->init = 1;

    return 0;
}

int destroyQueue(Queue** queue)
{

    if (*queue == NULL || (*queue)->init != 1) {
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
        //go from front to back
        Node* temp = queue->first;
        int set = 0;
        while (temp != NULL) {
            //find element with lower priority
            if (temp->priority < node->priority) {

                //if element being moved is not first in the list, inform next element
                //else set list first element to new one
                if (temp->previous) {
                    temp->previous->next = node;
                    node->previous = temp->previous;
                } else {
                    queue->first = node;
                }

                temp->previous = node;
                node->next = temp;

                set = 1;
                break;
            }
            temp = temp->next;
        }

        if (!set) {
            node->previous = queue->last;
            queue->last->next = node;
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

int isFullQueue(Queue* queue) {
    //Not created so it is empty
    if (queue == NULL) {
        return 0;
    }

    Node* node = (Node*) calloc(1, sizeof(Node));

    int full = node == NULL ? 1 : 0;

    free(node);
    //if its impossible to create node we can guess that queue is full
    return full;
}
