#include "graphlinkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList	*pList;
	
	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!pList)
		return (NULL);
	return(pList);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*curr;
	ListNode	*addNode;

	if (position < 0 || pList->currentElementCount < position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	addNode = (ListNode	*)calloc(1, sizeof(ListNode));
	*addNode = element; 
	curr = &pList->headerNode;
	for (int i = 0; i < position; i++)
		curr = curr->pLink;
	addNode->pLink = curr->pLink;
	curr->pLink = addNode;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	ListNode	*delNode;

	if (position < 0 || pList->currentElementCount <= position - 1)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	
	curr = &pList->headerNode;
	for (int i = 0; i < position - 1; i++)
		curr = curr->pLink;
	delNode = curr->pLink;
	curr->pLink = delNode->pLink;
	free(delNode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (NULL);
	}
	curr = &pList->headerNode;
	for (int i = 0; i <= position; i++)
		curr = curr->pLink;
	return (curr);
}

void clearLinkedList(LinkedList* pList)
{
	int position = pList->currentElementCount - 1;
	for (; 0 <= position; position--)
		removeLLElement(pList, position);
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList *pList)
{
	ListNode	*pNode;

	pNode = pList->headerNode.pLink;
	printf("Current List Length : %d\n", pList->currentElementCount);
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("tovertexID : %d\n",pNode->data.vertexID);
		printf("weight : %d\n",pNode->data.weight);
		pNode = pNode->pLink;
	}
	printf("\n");
	return ;
}
