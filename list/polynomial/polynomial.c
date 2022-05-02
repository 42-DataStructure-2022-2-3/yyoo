#include "polynomial.h"

int main()
{
    LinkedList	*List_A;
    LinkedList	*List_B;
	ListNode	new_node;

	List_A = createLinkedList();
	List_B = createLinkedList();

	addLLElement(List_A, 6, 6);
    addLLElement(List_A, 4, 5);
    addLLElement(List_A, 2, 2);


	addLLElement(List_B, 1, 5);
	addLLElement(List_B, 2, 4);
	addLLElement(List_B, 3, 2);
	addLLElement(List_B, 4, 0);
	LinkedList *sum;
	sum = sumpoly(List_A, List_B);
	printf("+++++++++++++++ LIST_A +++++++++++++++\n");
	displayLinkedList(List_A);
	printf("+++++++++++++++ LIST_B +++++++++++++++\n");
	displayLinkedList(List_B);
	printf("+++++++++++++++ SUM +++++++++++++++\n");
	displayLinkedList(sum);

}

LinkedList* createLinkedList()
{
	LinkedList	*pList;

	pList = calloc(1, sizeof(LinkedList));
	if (!pList)
		return (NULL);
	pList->headerNode.pLink = NULL;
	return (pList);
}

int addLLElement(LinkedList* pList, float coef, int degree)
{
	ListNode *curr;
	ListNode *add_node;

	if (degree < 0 || coef == 0 || findDegree(pList, degree))
		return (FALSE); //exit();
	add_node = calloc(1, sizeof(ListNode));
	add_node->coef = coef;
	add_node->degree = degree;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pLink = add_node;
		add_node->pLink = NULL;
	}
	else
	{
		curr = pList->headerNode.pLink;
		if (curr->degree < degree)
		{
			add_node->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = add_node;
		}
		else
		{
			while (curr->degree > degree && curr->pLink != NULL)
				curr = curr->pLink;
			add_node->pLink = curr->pLink;
			curr->pLink = add_node;
		}
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int degree)
{
	ListNode	*curr;
	ListNode	*remove_node;
	int			i;

	if (!findDegree(pList, degree))
		return (FALSE); //exit();
	i = 0;
	curr = &pList->headerNode;
	while (curr->pLink->degree > degree && curr->pLink != NULL)
		curr = curr->pLink;
	remove_node = curr->pLink;
	curr->pLink = remove_node->pLink;
	free(remove_node);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int degree)
{
	ListNode	*curr;

	if (!findDegree(pList, degree))
		return (NULL); //exit()
	curr = pList->headerNode.pLink;
	while (curr->degree != degree && curr->pLink != NULL)
		curr = curr->pLink;
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

void	displayLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	int			i;

	if (pList == NULL || pList->headerNode.pLink == NULL)
		return ;
	i = 0;
	curr = pList->headerNode.pLink;
	printf("currentElementCount : %d\n", pList->currentElementCount);
	while (curr != NULL)
	{
		printf("%d th data is %fx^%d\n", i + 1, curr->coef, curr->degree);
		curr = curr->pLink;
		i++;
	}
}

int findDegree(LinkedList* pList, int degree)
{
	ListNode *curr;

	curr = pList->headerNode.pLink;
	while (curr != NULL)
	{
		if (curr->degree == degree)
			return (TRUE);
		curr = curr->pLink;
	}
	return (FALSE);
}

LinkedList* sumpoly(LinkedList *A, LinkedList *B)
{
	LinkedList	*sum;
	ListNode	*curr_a;
	ListNode	*curr_b;

	if (A->currentElementCount == 0 || B->currentElementCount == 0)
	{
		if (A->currentElementCount == 0)
			return (B);
		else if (B->currentElementCount == 0)
			return (A);
		else
			return (NULL);
	}
	sum = createLinkedList();
	curr_a = A->headerNode.pLink;
	curr_b = B->headerNode.pLink;
	while (curr_a != NULL || curr_b != NULL)
	{
		if (curr_a != NULL && curr_b != NULL)
		{	
			if (curr_a->degree > curr_b->degree)
			{
				addLLElement(sum, curr_a->coef, curr_a->degree);
				curr_a = curr_a->pLink;
			}
			else if (curr_a->degree < curr_b->degree)
			{
				addLLElement(sum, curr_b->coef, curr_b->degree);
				curr_b = curr_b->pLink;
			}	
			else if (curr_a->degree == curr_b->degree)
			{
				addLLElement(sum, curr_a->coef + curr_b->coef, curr_a->degree);
				curr_a = curr_a->pLink;
				curr_b = curr_b->pLink;
			}
		}		
		else if (curr_a == NULL)
		{
			addLLElement(sum, curr_b->coef, curr_b->degree);
			curr_b = curr_b->pLink;
		}
		else if (curr_b == NULL)
		{
			addLLElement(sum, curr_a->coef, curr_a->degree);
			curr_a = curr_a->pLink;
		}
	
	}
	return (sum);
}
