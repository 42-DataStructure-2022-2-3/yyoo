#include "linkeddeque.h"

int main()
{
	LinkedDeque *LD = createLinkedDeque();
	DequeNode element;

	for(int i = 0; i < 3; i++)
	{
		element.data = 'a' + i;
		insertFrontLD(LD, element);		
	}
	displayLinkdeDeque(LD);
	// deleteRearLD(LD)
	// printf("++++++++++++++++++\n");
	// displayLinkdeDeque(LD);

	deleteFrontLD(LD);
	deleteFrontLD(LD);
	deleteFrontLD(LD);
	displayLinkdeDeque(LD);
	system("leaks a.out");
}

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *LD;

	LD = calloc(1, sizeof(LinkedDeque));
	LD->pFrontNode = NULL;
	LD->pRearNode = NULL;
	return (LD);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new_node;

	new_node = calloc(1, sizeof(DequeNode));
	*new_node = element;
	new_node->pLLink = NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		new_node->pRLink = NULL;
		pDeque->pRearNode = new_node;
	}
	else
	{
		new_node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = new_node;
	}
	pDeque->pFrontNode = new_node;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new_node;

	new_node = calloc(1,  sizeof(DequeNode));
	*new_node = element;
	new_node->pRLink = NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		new_node->pLLink = NULL;
		pDeque->pFrontNode = new_node;
	}
	else
	{
		new_node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode->pRLink = new_node;
	}
	pDeque->pRearNode = new_node;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *de;
	DequeNode *second;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	de = pDeque->pFrontNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		second = pDeque->pFrontNode->pRLink;
		second->pLLink = NULL;
		pDeque->pFrontNode = second;
	}
	pDeque->currentElementCount--;
	return (de);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *de;
	DequeNode *second;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	de = pDeque->pRearNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		second = pDeque->pRearNode->pLLink;
		second->pRLink = NULL;
		pDeque->pRearNode = second;
	}
	pDeque->currentElementCount--;
	return (de);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *curr;
	int	i = 0;

	while (i < pDeque->currentElementCount)
	{
		curr = pDeque->pFrontNode;
		pDeque->pFrontNode = curr->pRLink;
		free(curr);
		i++;
	}
	free(pDeque);
	pDeque = NULL;
}

int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayLinkdeDeque(LinkedDeque* pQueue)
{
	DequeNode *curr;
	int i = 0;

	printf("currentElementCount : %d\n", pQueue->currentElementCount);
	if (!isLinkedDequeEmpty(pQueue))
	{
		curr = pQueue->pFrontNode;
		while (curr != NULL)
		{
			printf("[%d] : %c ", i, curr->data);
			curr = curr->pRLink;
			i++;
		}
		printf("\n");
	}
}