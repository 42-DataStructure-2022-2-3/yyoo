#include "circularqueue.h"

int main()
{
	ArrayQueue *aq = createArrayQueue(10);
	ArrayQueueNode aqn;

	int i = 0;
	while (i < 4)
	{
		aqn.data = 'a' + i;
		enqueueAQ(aq, aqn);
		i++;
	}
	aq->front = 5;
	aq->rear = 4;
	displayCircularQueue(aq);
	// for (int j = 0; j < 10; j++)
	// {
	// 	printf("+++++++++  %d  ++++++++++++\n", j);
	// 	displayArrayQueue(aq);
	// 	dequeueAQ(aq);
	// }
	// printf("+++++++++  10  ++++++++++++\n");
}

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *aq;

	if (maxElementCount > 0)
	{
		aq = calloc(1, sizeof(ArrayQueue));
		aq->maxElementCount = maxElementCount;
		aq->currentElementCount = 0;
		aq->front = 0;
		aq->rear = -1;
		aq->pElement = calloc(maxElementCount, sizeof(ArrayQueueNode));
	}
	return (aq);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue->rear == pQueue->maxElementCount - 1)
		return (FALSE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *de;

	if (isArrayQueueEmpty(pQueue))
		return (NULL);
	de = malloc(sizeof(ArrayQueueNode));
	*de = pQueue->pElement[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (de);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *peek;

	if (isArrayQueueEmpty(pQueue))
		return (NULL);
	peek = malloc(sizeof(ArrayQueueNode));
	*peek = pQueue->pElement[pQueue->front];
	return (peek);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
	pQueue = NULL;
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue->maxElementCount == pQueue->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayCircularQueue(ArrayQueue *pQueue) {
    if (pQueue != NULL) {
        // int i = (pQueue->front + 1)%pQueue->maxElementCount;
        int i = pQueue->front;

        printf("CircularQueue\nmax count : %d\tcurrent count : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);
        printf("front : %d, rear : %d\n", pQueue->front, pQueue->rear);
        while (i != pQueue->rear) {
            i = (i + 1)%pQueue->maxElementCount;
            printf("CircularQueue[%d] = %c\n", i, pQueue->pElement[i].data);
            if (i == pQueue->rear) break;
        }
    }
}
/*
void displayArrayQueue(ArrayQueue* pQueue)
{
	printf("maxElementCount : %d\n", pQueue->maxElementCount);
	printf("currentElementCount : %d\n", pQueue->currentElementCount);
	printf("front : %d\n", pQueue->front);
	printf("rear : %d\n", pQueue->rear);
	if (pQueue->rear != -1 && pQueue->currentElementCount > 0)
	{
		int i = pQueue->front;
		while (i <= pQueue->rear)
		{
			printf("pElement[%d] : %c\n", i, pQueue->pElement[i].data);
			i++;
		}
	}
}
*/