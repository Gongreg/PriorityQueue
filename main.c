#include "queue.h"

int main()
{
    Queue* queue;
    initQueue(&queue);
    isEmptyQueue(queue);
    pushQueue(queue, 5, 1);
    pushQueue(queue, 4, 2);
    pushQueue(queue, 5, 1);
    pushQueue(queue, 4, 4);
    pushQueue(queue, 3, 3);
    popQueue(queue);
    destroyQueue(&queue);
    return 0;
}
