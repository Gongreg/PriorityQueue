//Priority queue - Gytis Vinclovas II grupe

#ifndef queueh
#define queueh

#include "queue_data.h"

typedef struct Node {
    Data value;
    int priority;
    struct Node* previous;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* first;
    struct Node* last;
    int length;
    int init;
} Queue;

//Error codes are sent back as result. Check queue_codes.h for help.
int initQueue(Queue** queue);
int destroyQueue(Queue** queue);
int pushQueue(Queue* queue, Data value, int priority);
int popQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
int isFullQueue(Queue* queue);

#endif
