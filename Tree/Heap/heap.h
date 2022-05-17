#ifndef _HEAP_
#define _HEAP_

typedef struct HeapNodeType
{
	int key;
	char data;
} HeapNode;

typedef struct HeapType
{
    int maxElementCount;
    int currentElementCount;
	HeapNode* Node;
} Heap;

Heap* makeHeap(int maxElementCount);
HeapNode* getRootNodeHP(Heap* pHeap);
HeapNode* insertChildNodeHP(Heap* Heap, HeapNode element);
Heap* deleteMaxHeap(Heap* Heap);
void MaxHeapify(Heap* Heap, int now);
void displayHeap(Heap* Heap);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#include <stdio.h>
#include <stdlib.h>

#endif