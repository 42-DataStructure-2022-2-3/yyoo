#include "arrayqueue.h"

int main()
{
	ArrayQueue *aq = createArrayQueue(10);
	ArrayQueueNode aqn;

	int i = 0;
	while (i < 10)
	{
		aqn.data = 'a' + i;
		enqueueAQ(aq, aqn);
		i++;
	}
	for (int j = 0; j < 10; j++)
	{
		printf("+++++++++  %d  ++++++++++++\n", j);
		displayArrayQueue(aq);
		dequeueAQ(aq);
	}
	printf("+++++++++  10  ++++++++++++\n");
	displayArrayQueue(aq);
}

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *aq;

	if (maxElementCount > 0)
	{
		aq = calloc(1, sizeof(ArrayQueue));
		aq->maxElementCount = maxElementCount;
		aq->currentElementCount = 0;
		aq->front = -1;
		aq->rear = -1;
		aq->pElement = calloc(maxElementCount, sizeof(ArrayQueueNode));
	}
	return (aq);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue->rear == pQueue->maxElementCount - 1)
		return (FALSE);
	pQueue->rear++;
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
	pQueue->front++;
	*de = pQueue->pElement[pQueue->front];
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
