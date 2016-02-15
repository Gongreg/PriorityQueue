#include "queue.h"
#include "queue_write.h"

int main()
{
    Queue* queue;
    printMessage(initQueue(&queue));
    printMessage(destroyQueue(&queue));
    mapQueue(queue);
    // push(list, 5);
    // push(list, 7);
    // push(list, 3);
    //
    // mapList(list);
    //
    // removeLowest(list);
    // mapList(list);
    // removeLowest(list);
    // push(list, 1);
    // mapList(list);
    // push(list, 10);
    // removeLowest(list);
    // mapList(list);
    // push(list, 30);
    // destroyList(&list);

    return 0;
}
