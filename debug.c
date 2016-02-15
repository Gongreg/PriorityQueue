#include "queue.h"
#include "queue_write.h"

int main()
{
    Queue* queue;
    printMessage(initQueue(&queue));
    printEmpty(isEmptyQueue(queue));
    printMessage(pushQueue(queue, 5, 1));
    printMessage(pushQueue(queue, 4, 2));
    printMessage(pushQueue(queue, 5, 1));
    printMessage(pushQueue(queue, 4, 4));
    mapQueue(queue);
    printMessage(popQueue(queue));
    mapQueue(queue);
    printMessage(popQueue(queue));
    mapQueue(queue);
    printMessage(popQueue(queue));
    mapQueue(queue);
    printMessage(popQueue(queue));
    mapQueue(queue);
    printMessage(popQueue(queue));
    mapQueue(queue);
    printMessage(destroyQueue(&queue));
    return 0;
}
