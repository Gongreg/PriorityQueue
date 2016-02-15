#ifndef queueh
#define queueh 1
typedef int Data;

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
} Queue;

int initQueue(Queue** queue);
int destroyQueue(Queue** queue);
int pushQueue(Queue* queue, Data value, int priority);
int popQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
int isFullQueue(Queue* queue);

#endif
