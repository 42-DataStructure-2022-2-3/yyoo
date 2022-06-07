#include "shortest_path.h"

int	*dijkstra(LinkedGraph *pGraph, int startVertexId)
{
	HeapBucket	*pMinheap = createHeap(pGraph->maxVertexCount);
	HeapNode	*popMinNode;
	HeapNode element;
	int	*path = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	ListNode *curr;

	for (int i = 0; i < pGraph->maxVertexCount; i++)
		path[i] = INF;

	path[startVertexId] = 0;
	element.tovertexID = startVertexId;
	element.data = 0;
	addMinHeapElement(pMinheap, element);

	while (!isHeapEmpty(pMinheap))
	{
		popMinNode = deleteMinHeapElement(pMinheap);
		curr = pGraph->ppAdjEdge[popMinNode->tovertexID]->headerNode.pLink;
		while (curr)
		{
			int currVertexID = curr->data.vertexID;
			int currWeight = curr->data.weight;
			if (path[currVertexID] > path[popMinNode->tovertexID] + currWeight)
			{
				path[currVertexID] = path[popMinNode->tovertexID] + currWeight;
				element.tovertexID = currVertexID;
				element.data = path[currVertexID];
				addMinHeapElement(pMinheap, element);
			}
			curr = curr->pLink;
		}
	}
	return path;
}


