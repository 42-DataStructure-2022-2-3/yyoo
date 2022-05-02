#include "linkedlist.h"

int main()
{
	LinkedList	*List;
	ListNode	new_node;

	List = createLinkedList();

	int i = 0;
	while (i < 10)
	{
		new_node.data = i;
		addLLElement(List, i + 1, new_node);
		i++;
	}
	// clearLinkedList(List);
	displayLinkedList(List);
	removeLLElement(List, 2);
	printf("+++++++++++++afterremove+++++++++++++++++\n");
	// deleteLinkedList(List);
	displayLinkedList(List);
}

void	displayLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	int			i;

	i = 0;
	curr = pList->headerNode.pLink;
	printf("currentElementCount : %d\n", pList->currentElementCount);
	while (curr != NULL)
	{
		printf("%d th data is %d\n", i + 1, curr->data);
		curr = curr->pLink;
		i++;
	}
}

LinkedList* createLinkedList()
{
	LinkedList	*pList;

	pList = malloc(sizeof(LinkedList));
	if (!pList)
		return (NULL);
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
	return (pList);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*new_node;
	ListNode	*curr;
	int			i;

	if (position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	i = 0;
	if (!new_node = malloc(sizeof(ListNode)))
		return (FALSE);
	*new_node = element;
	curr = &pList->headerNode;
	while (i < position - 1)
	{
		curr = curr->pLink;
		i++;
	}
	new_node->pLink = curr->pLink;
	curr->pLink = new_node;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	ListNode	*remove_node;
	int			i;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	i = 0;
	curr = &pList->headerNode;
	while (i < position - 1)
	{
		curr = curr->pLink;
		i++;
	}
	remove_node = curr->pLink;
	curr->pLink = remove_node->pLink;
	free(remove_node);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	int			i;

	i = 0;
	curr = &pList->headerNode;
	while (i < position)
	{
		curr = curr->pLink;
		i++;
	}
	return (curr);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	int			count;

	count = pList->currentElementCount;
	while (count > 0)
	{
		removeLLElement(pList, count);
		count--;
	}
	pList->currentElementCount = 0;
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
	pList = NULL;
}
