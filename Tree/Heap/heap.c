#include "heap.h"

int main()
{
    Heap *Hp = makeHeap(10);

	int i = 1;
	while (i < 8)
	{
		HeapNode node;
		node.key = i;
		insertChildNodeHP(Hp, node);
		i++;
	}
	i++;

	deleteMaxHeap(Hp);
	deleteMaxHeap(Hp);


}
//		          5(1)
//        4(2)            2(3)
//    1(4)     3(5)      
//  temp = 5
Heap* makeHeap(int maxElementCount)
{
	Heap *Hp;

	Hp = calloc(1, sizeof(Heap));
	Hp->Node = calloc(maxElementCount + 1, sizeof(HeapNode));
	Hp->maxElementCount = maxElementCount;
	return(Hp);
}

HeapNode* getRootNodeHP(Heap* pHeap)
{
	return (&(pHeap->Node[1]));
}

HeapNode* insertChildNodeHP(Heap* Heap, HeapNode element)
{
	int now;
	if (Heap->maxElementCount == Heap->currentElementCount || !Heap)
		return (NULL);
	Heap->currentElementCount++;
	Heap->Node[Heap->currentElementCount] = element;
//         20
//      2     10
//   4    5  8
//
	now = Heap->currentElementCount;
	while (Heap->Node[now / 2].key < element.key && 1 < now)
	{
		MaxHeapify(Heap, now);
		now /= 2;
	}
	return (&(Heap->Node[now]));
}

Heap* deleteMaxHeap(Heap* Heap)
{
	int now;

	Heap->Node[1] = Heap->Node[Heap->currentElementCount];
	Heap->Node[Heap->currentElementCount].key = 0;
	Heap->Node[Heap->currentElementCount].data = 0;
	now = Heap->currentElementCount / 2;
	while (Heap->Node[now / 2].key < Heap->Node[now].key && 1 < now)
	{
		MaxHeapify(Heap, now);
		now /= 2;
	}
	Heap->currentElementCount--;
	return (Heap);
}

void MaxHeapify(Heap* Heap, int now)
{
	HeapNode tmp;

	tmp = Heap->Node[now];
	Heap->Node[now] = Heap->Node[now/2];
	Heap->Node[now/2] = tmp;
}

void displayHeap(Heap* Heap)
{
	for(int j = 1; j <= Heap->currentElementCount; j++)
	{
		printf("%d\n", Heap->Node[j].key);
	}
}