#include "doublylist.h"

int main()
{
	DoublyList *pList;

	pList = createDoublyList();
	int i = 1;
	DoublyListNode Node;

	Node.data = 1;
	while (i < 5)
	{
		addDLElement(pList, i, Node);
		Node.data++;
		i++;
	}
	getDLElement(pList, 3);
	//deleteDoublyList(pList);
	// removeDLElement(pList, 2);
	// displayDoublyList(pList);

	// printf("+++++++++++++++++++++++++++++++++++\n");
	// RdisplayDoublyList(pList);
	return 0;
}

DoublyList* createDoublyList()
{
	DoublyList *pList;

	pList = malloc(sizeof(DoublyList));
	if (!pList)
		return (NULL);
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = NULL;
	pList->headerNode.pRLink = NULL;
	return (pList);
}

void deleteDoublyList(DoublyList* pList)
{
	clearDoublyList(pList);
	free(pList);
	pList = NULL;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *add_node;
	DoublyListNode *curr;

	if (position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	add_node = malloc(sizeof(DoublyListNode));
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

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *curr;

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

void clearDoublyList(DoublyList* pList)
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

int getDoublyListLength(DoublyList* pList)
{
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*curr;
	int i;

	if (position > pList->currentElementCount)
		return (NULL);
	curr = &pList->headerNode;
	for(i = 0; i < position; i++)
		curr = curr->pRLink;
	return (curr);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*curr;

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

void RdisplayDoublyList(DoublyList* pList)
{
	int j = 1;
	DoublyListNode *curr;

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