#ifndef _LINKEDLIST_
#define _LINKEDLIST_

# include <stdlib.h>
# include <stdio.h>

typedef struct ListNodeType
{
	float	coef;
	int degree;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList*	createLinkedList();
int			addLLElement(LinkedList* pList, float coef, int degree);
int			removeLLElement(LinkedList* pList, int degree);
ListNode*	getLLElement(LinkedList* pList, int degree);
void		clearLinkedList(LinkedList* pList);
int			getLinkedListLength(LinkedList* pList);
void		deleteLinkedList(LinkedList* pList);
void		displayLinkedList(LinkedList* pList);
int 		findDegree(LinkedList* pList, int degree);
LinkedList	*sumpoly(LinkedList *A, LinkedList *B);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif