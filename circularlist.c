#include "circularlist.h"

int main()
{
	CircularList *pList;

	pList = createCircularList();
	int i = 1;
	CircularListNode Node;

	Node.data = 1;
	while (i < 5)
	{
		addDLElement(pList, i, Node);
		Node.data++;
		i++;
	}
	getDLElement(pList, 3);
	// deleteCircularList(pList);
	// removeDLElement(pList, 2);
	// displayCircularList(pList);

	// printf("+++++++++++++++++++++++++++++++++++\n");
	// RdisplayCircularList(pList);
	return 0;
}

CircularList* createCircularList()
{
	CircularList *pList;

	pList = malloc(sizeof(CircularList));
	if (!pList)
		return (NULL);
	pList->currentElementCount = 0;
	pList->headerNode->pLLink = NULL;
	pList->headerNode->pRLink = NULL;
	return (pList);
}

void deleteCircularList(CircularList* pList)
{
	clearCircularList(pList);
	free(pList);
	pList = NULL;
}

int addDLElement(CircularList* pList, int position, CircularListNode element)
{
	CircularListNode *add_node;
	CircularListNode *curr;

	if (position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	add_node = malloc(sizeof(CircularListNode));
	if (!add_node)
		return (FALSE);
	add_node->data = element.data;
	curr = &pList->headerNode;
	for (int i = 0; i < position - 1 ; i++)
		curr = curr->pRLink;
	add_node->pRLink = curr->pRLink;
	add_node->pLLink = curr;
	if (position < pList->currentElementCount)
		add_node->pRLink->pLLink = add_node;
	curr->pRLink = add_node;
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(CircularList* pList, int position)
{
	CircularListNode *curr;

	if (position > pList->currentElementCount)
		return (FALSE);
	curr = &pList->headerNode;
	for (int i = 0; i < position ; i++)
		curr = curr->pRLink;
	curr->pLLink->pRLink = curr->pRLink;
	if (position < pList->currentElementCount)
		curr->pRLink->pLLink = curr->pLLink;
	free(curr);
	pList->currentElementCount--;
	return (TRUE);
}

void clearCircularList(CircularList* pList)
{
	int i = pList->currentElementCount;

	while (i > 0)
	{
		removeDLElement(pList, i);
		i--;
	}
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = NULL;
	pList->headerNode.pRLink = NULL;
}

int getCircularListLength(CircularList* pList)
{
	return (pList->currentElementCount);
}

CircularListNode* getDLElement(CircularList* pList, int position)
{
	CircularListNode	*curr;
	int i;

	if (position > pList->currentElementCount)
		return (NULL);
	curr = &pList->headerNode;
	for(i = 0; i < position; i++)
		curr = curr->pRLink;
	return (curr);
}

void displayCircularList(CircularList* pList)
{
	CircularListNode	*curr;

	if (pList == NULL)
		return ;
	int i = 1;
	printf("currentElementCount is %d\n", pList->currentElementCount);
	curr = &pList->headerNode;
	for(curr = &pList->headerNode; curr->pRLink != NULL; )
	{
		curr = curr->pRLink;
		printf("%d th data is %d\n", i++, curr->data);
	}
}

void RdisplayCircularList(CircularList* pList)
{
	int j = 1;
	CircularListNode *curr;

	curr = &pList->headerNode;
	while (curr->pRLink != NULL)
	{
		curr = curr->pRLink;
		j++;
	}
	j--;
	while (curr->pLLink != NULL)
	{
		printf("%d : %d\n", j, curr->data);
		curr = curr->pLLink;
		j--;
	}
}