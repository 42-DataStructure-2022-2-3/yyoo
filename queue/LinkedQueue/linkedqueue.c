#include "linkedqueue.h"

int main()
{
	LinkedQueue *LQ = createLinkedQueue();
	LinkedQueueNode node;

	for(int i = 0; i < 5; i++)
	{
		// printf("++++++++++  %d  ++++++++++\n", i);
		node.data = 'a' + i;
		enqueueLQ(LQ, node);
		// displayLinkedQueue(LQ);
		// printf("\n");
		// printf("\n");
	}
	displayLinkedQueue(LQ);
	printf("\n");
	
	

	system("leaks a.out");
	// int j = 0;
	// while (LQ->pFrontNode != NULL)
	// {
	// 	printf("++++++++++  %d  ++++++++++\n", j);
	// 	dequeueLQ(LQ);
	// 	displayLinkedQueue(LQ);
	// 	printf("\n");
	// 	printf("\n");
	// 	j++;
	// }

}

LinkedQueue* createLinkedQueue()
{
	LinkedQueue *LQ;

	LQ = calloc(1, sizeof(LinkedQueue));
	LQ->pFrontNode = NULL;
	LQ->pRearNode = NULL;
	return (LQ);
}

int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element)
{
	LinkedQueueNode *new_node;

	new_node = calloc(1, sizeof(LinkedQueueNode));
	*new_node = element;
	new_node->pLink = NULL;
	if (isLinkedQueueEmpty(pQueue))
		pQueue->pFrontNode = new_node;
	else
		pQueue->pRearNode->pLink = new_node;
	pQueue->pRearNode = new_node;
	pQueue->currentElementCount++;
	return (TRUE);
}

LinkedQueueNode *dequeueLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode *de;
	LinkedQueueNode *second;

	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	de = pQueue->pFrontNode;
	if (pQueue->currentElementCount == 1)
	{
		free(pQueue->pFrontNode);
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else
	{
		second = pQueue->pFrontNode->pLink;
		free(pQueue->pFrontNode);
		pQueue->pFrontNode = second;
	}
	pQueue->currentElementCount--;
	return (de);
}

LinkedQueueNode *peekLQ(LinkedQueue* pQueue)
{
	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	return (pQueue->pFrontNode);
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	LinkedQueueNode *curr;

	while (pQueue->currentElementCount > 1)
	{
		curr = pQueue->pFrontNode->pLink;
		free(pQueue->pFrontNode);
		pQueue->pFrontNode = curr;
		pQueue->currentElementCount--;
	}
	free(pQueue->pFrontNode);
	free(pQueue);
	pQueue = NULL;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayLinkedQueue(LinkedQueue* pQueue)
{
	LinkedQueueNode *curr;
	int i = 0;

	printf("currentElementCount : %d\n", pQueue->currentElementCount);
	// if (pQueue->currentElementCount > 1)
		curr = pQueue->pFrontNode;
	while (i < pQueue->currentElementCount)
	{
		printf("[%d] : %c, ", i, curr->data);
		curr = curr->pLink;
		i++;
	}
}

