#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct GraphVertexType
{
	int vertexID;		// ��� ID
	int weight;			// ����ġ.
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	ListNode headerNode;		// ��� ���(Header Node)
} LinkedList;

typedef struct LinkedGraphType
{
	int maxVertexCount;		// �ִ� ��� ����
	int currentVertexCount;	// ���� ���Ǵ� ����� ����
	int graphType;			// 1-Undirected, 2-Directed
	LinkedList **ppAdjEdge;		// ���� ������ ���� 2���� Linked
	int *pVertex;
	int *visited;		// ��� ������ ���� 1���� Linked
} LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
void deleteLinkedGraph(LinkedGraph* pGraph);
int isEmptyLG(LinkedGraph* pGraph);
int addVertexLG(LinkedGraph* pGraph, int vertexID);
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int checkVertexValid(LinkedGraph* pGraph, int vertexID);
int removeVertexLG(LinkedGraph* pGraph, int vertexID);
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void displayLinkedGraph(LinkedGraph* pGraph);

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
void displayLinkedList(LinkedList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				-1

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#define VISITED				1
#define NOT_VISITED			0
#endif
