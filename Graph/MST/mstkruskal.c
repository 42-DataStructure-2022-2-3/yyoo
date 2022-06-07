#include "mst.h"

LinkedGraph *mstKruskal(LinkedGraph *pGraph)
{
    LinkedGraph *mst = createLinkedGraph(pGraph->maxVertexCount);
    if (!mst) return NULL;

    HeapBucket *minheap = orderEdge(pGraph);
    printHeapArray(minheap);

    for (int i = 0; i < pGraph->edgecount; i++)
    {
        HeapNode *minedgenode = deleteMinHeapElement(minheap);
        // printf("fromvertexid : %d , tovertexid : %d, weight : %d\n", minedgenode->fromvertexID, minedgenode->tovertexID, minedgenode->data);
        if (!cyclecheck(mst, minedgenode->fromvertexID, minedgenode->tovertexID))
        {
            addVertexLG(mst, minedgenode->fromvertexID);
            addVertexLG(mst, minedgenode->tovertexID);
            addEdgewithWeightLG(mst, minedgenode->fromvertexID, minedgenode->tovertexID, minedgenode->data);
        }

        if (mst->currentVertexCount == pGraph->currentVertexCount)
            break ;
    }
    return mst;
}

HeapBucket *orderEdge(LinkedGraph *pGraph)
{
    HeapBucket *minheap = createHeap(pGraph->edgecount);
    if (!minheap) return NULL;

    ListNode *curr;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
            curr = pGraph->ppAdjEdge[i]->headerNode.pLink;
            while (curr)
            {
                if (i < curr->data.vertexID)
                {
                    HeapNode element = {0, };
                    element.visited = 0;
                    element.data = curr->data.weight;
                    element.fromvertexID = i;
                    element.tovertexID = curr->data.vertexID;
                    addMinHeapElement(minheap, element);
                }
                curr = curr->pLink;
            }
    }
    return minheap;
}

int cyclecheck(LinkedGraph *mst, int fromvertexID, int tovertexID)
{
    int		next;
	ListNode	*curr;
	ArrayStack	*pStack;
	StackNode	element;

    int *pvisited = calloc(mst->maxVertexCount, sizeof(int));

	pStack = createArrayStack(mst->maxVertexCount);
	pvisited[fromvertexID] = VISITED;
	element.data = fromvertexID;
	pushAS(pStack, element);
	while(!isArrayStackEmpty(pStack))
	{
		StackNode *u = popAS(pStack);
		// printf("%d\n", u->data);
		fromvertexID = u->data;
        if (fromvertexID == tovertexID) return TRUE;
		curr = mst->ppAdjEdge[fromvertexID]->headerNode.pLink;
		while (curr)
		{
			 if (pvisited[curr->data.vertexID] == NOT_VISITED)
	 		{
				pvisited[curr->data.vertexID] = VISITED;
				element.data = curr->data.vertexID;
				pushAS(pStack, element);
			}
			curr = curr->pLink;
		}
	}
    return FALSE;
}
