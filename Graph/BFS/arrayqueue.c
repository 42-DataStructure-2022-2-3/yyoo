#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *queue;

    queue = (ArrayQueue*)calloc(1, sizeof(ArrayQueue));
    queue->maxElementCount = maxElementCount;
    queue->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
    return (queue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (isArrayQueueFull(pQueue))
        return (FALSE);

    pQueue->pElement[pQueue->rear].data = element.data;
    //  printf("+ enqueue '%c'\n", pQueue->pElement[pQueue->rear].data);
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    // maxElementCount = 4, pQueue->rear = 3 일 경우에는 다음에 추가될 노드는 0번 인덱스로 가야함 
    pQueue->currentElementCount++;
   
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode  *retNode;

    if(isArrayQueueEmpty(pQueue))
        return (NULL);
    retNode = (ArrayQueueNode *)calloc(1, sizeof(ArrayQueueNode));

    *retNode = pQueue->pElement[pQueue->front];
    // memset(&(pQueue->pElement[pQueue->front]), 0, sizeof(ArrayQueueNode));
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount--;
    // printf("- dequeue '%c'\n", retNode->data);
    return (retNode);
}
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if(isArrayQueueEmpty(pQueue))
        return (NULL);
    // printf("peekQueue = '%c'\n", pQueue->pElement[pQueue->front].data);
    return (&pQueue->pElement[pQueue->front]);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    free(pQueue->pElement);
    free(pQueue);
    memset(pQueue, 0, sizeof(ArrayQueue));
}

int isArrayQueueFull(ArrayQueue* pQueue)
{ 
    return (pQueue->currentElementCount != 0 && pQueue->maxElementCount != pQueue->currentElementCount && pQueue->front == pQueue->rear);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    return (pQueue->currentElementCount == 0);
}

void displayArrayQueue(ArrayQueue *pQueue)
{
    int j;

    // printf("front <-[");
    for (int i = 0; i < pQueue->currentElementCount; i++)
    {
        j = (pQueue->front + i) % pQueue->maxElementCount;
        // printf("%c",pQueue->pElement[j].data);
        // if (i != pQueue->currentElementCount - 1)
            // printf(", ");
    }
    // printf("]-> rear\n");
}
