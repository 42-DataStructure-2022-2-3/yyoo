#include "mst.h"

LinkedGraph *mstprim(LinkedGraph *pGraph, int startVertexID)
{
    minWeightEdge minEdge = {0, };
    LinkedGraph *mst = createLinkedGraph(pGraph->maxVertexCount);
    if (!mst) return NULL;

    addVertexLG(mst, startVertexID);
    while (mst->currentVertexCount < pGraph->currentVertexCount)
    {
        minEdge.weight = INF;
        for (int i = 0; i < pGraph->currentVertexCount; i++)
        {
            if (mst->pVertex[i] == USED)
                getminWeightEdge(pGraph, mst, i, &minEdge);
        }
        addVertexLG(mst, minEdge.tovertexID);
        addEdgewithWeightLG(mst, minEdge.fromvertexID, minEdge.tovertexID, minEdge.weight);
    }
    return mst;
}

void getminWeightEdge(LinkedGraph *pGraph,LinkedGraph *mst, int fromVertexID, minWeightEdge *minEdge)
{
    ListNode *curr;


    curr = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
    while (curr)
    {
        if (curr->data.weight < minEdge->weight)
        {
            if (!isalready(mst, fromVertexID, curr->data.vertexID))
            {
                if (!cyclecheck(mst, fromVertexID, curr->data.vertexID))
                {
                    minEdge->weight = curr->data.weight;
                    minEdge->fromvertexID = fromVertexID;
                    minEdge->tovertexID = curr->data.vertexID;
                }
            }
        }
        curr = curr->pLink;
    }
}

int isalready(LinkedGraph *mst, int fromVertexID, int toVertexID)
{
    ListNode *curr;
    curr = mst->ppAdjEdge[fromVertexID]->headerNode.pLink;
    while (curr)
    {
        if (curr->data.vertexID == toVertexID)
            return (TRUE);
        curr = curr->pLink;
    }
    return (FALSE);
}

// int cyclecheck(LinkedGraph *mst, int fromvertexID, int tovertexID)
// {
//     int		next;
// 	ListNode	*curr;
// 	ArrayStack	*pStack;
// 	StackNode	element;

//     int *pvisited = calloc(mst->maxVertexCount, sizeof(int));

// 	pStack = createArrayStack(mst->maxVertexCount);
// 	pvisited[fromvertexID] = VISITED;
// 	element.data = fromvertexID;
// 	pushAS(pStack, element);
// 	while(!isArrayStackEmpty(pStack))
// 	{
// 		StackNode *u = popAS(pStack);
// 		// printf("%d\n", u->data);
// 		fromvertexID = u->data;
//         if (fromvertexID == tovertexID) return TRUE;
// 		curr = mst->ppAdjEdge[fromvertexID]->headerNode.pLink;
// 		while (curr)
// 		{
// 			 if (pvisited[curr->data.vertexID] == NOT_VISITED)
// 	 		{
// 				pvisited[curr->data.vertexID] = VISITED;
// 				element.data = curr->data.vertexID;
// 				pushAS(pStack, element);
// 			}
// 			curr = curr->pLink;
// 		}
// 	}
//     return FALSE;
// }

