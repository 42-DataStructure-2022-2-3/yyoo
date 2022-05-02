#include "posstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *newLS;

	newLS = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	newLS->pTopElement = NULL;
	return (newLS);
}

int	pushLS(LinkedStack* pStack, MapPosition element)
{
	MapPosition *newNode;

	newNode = (MapPosition *)calloc(1, sizeof(MapPosition));
	*newNode = element;
	if (pStack->pTopElement == NULL)
		pStack->pTopElement = newNode;
	else
	{
		newNode->pLink = pStack->pTopElement;
		pStack->pTopElement = newNode;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

MapPosition* popLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	MapPosition	*popNode;
	popNode = pStack->pTopElement;
	pStack->pTopElement = popNode->pLink;
	--(pStack->currentElementCount);
	return (popNode);
}

MapPosition* peekLS(LinkedStack* pStack)
{
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return ;

	MapPosition	*delNode;

	while (pStack->pTopElement)
	{
		delNode = popLS(pStack);
		free(delNode);
		--(pStack->currentElementCount);
	}
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}