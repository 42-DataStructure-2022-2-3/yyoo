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
	clearCircularList(pList);
	//getDLElement(pList, 3);
	// deleteCircularList(pList);
	// removeDLElement(pList, 2);
	displayCircularList(pList);

	// printf("+++++++++++++++++++++++++++++++++++\n");
	return 0;
}

CircularList* createCircularList()
{
	CircularList *pList;

	pList = calloc(1, sizeof(CircularList));
	if (!pList)
		return (NULL);
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
	CircularListNode *Last_node;
	CircularListNode *curr;

	if (position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	add_node = malloc(sizeof(CircularListNode));
	if (!add_node)
		return (FALSE);
	*add_node = element;
	if (position == 1)
	{
		if (pList->headerNode == NULL)
		{
			pList->headerNode = add_node;
			add_node->pLink = add_node;
		}
		else
		{
			add_node->pLink = pList->headerNode;
			pList->headerNode = add_node;
			Last_node = getDLElement(pList, pList->currentElementCount);
			Last_node->pLink = add_node;
		}
	}
	else
	{
		curr = pList->headerNode;
		for (int i = 0; i < position - 2; i++)
			curr = curr->pLink;
		add_node->pLink = curr->pLink;
		curr->pLink = add_node;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(CircularList* pList, int position)
{
	CircularListNode *RemoveNode;
	CircularListNode *curr;
	CircularListNode	*LastNode;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (position == 1)
	{
		RemoveNode = pList->headerNode;
		if (pList->currentElementCount == 1)
		{
			free(RemoveNode);
			pList->headerNode = NULL;
		}
		else
		{
			LastNode = getDLElement(pList, pList->currentElementCount);
			pList->headerNode = pList->headerNode->pLink;
			LastNode->pLink = pList->headerNode;
			free(RemoveNode);
		}
	}
	else
	{
		curr = pList->headerNode;
		for (int i = 0; i < position - 2; i++)
			curr = curr->pLink;
		RemoveNode = curr->pLink;
		curr->pLink = RemoveNode->pLink;
		free(RemoveNode);
	}
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
	pList->headerNode = NULL;
}

int getCircularListLength(CircularList* pList)
{
	return (pList->currentElementCount);
}

CircularListNode* getDLElement(CircularList* pList, int position)
{
	CircularListNode	*curr;
	int i;

	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode;
	for(i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

void displayCircularList(CircularList* pList)
{
	CircularListNode	*curr;

	if (pList == NULL)
		return ;
	int i = 1;
	printf("currentElementCount is %d\n", pList->currentElementCount);
	curr = pList->headerNode;
	for(curr = pList->headerNode; i <= pList->currentElementCount; i++)
	{
		printf("%d th data is %d\n", i, curr->data);
		curr = curr->pLink;
	}
}
