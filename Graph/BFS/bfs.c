#include "bfs.h"

void	traversal_BFS (int vertexID, LinkedGraph *pGraph) 
{ 
	ArrayQueue *Q =createArrayQueue(pGraph->maxVertexCount);
	ArrayQueueNode element;
	ListNode *curr;

	pGraph->visited[vertexID] = VISITED;
	element.data = vertexID;
	enqueueAQ(Q, element);
	while(!isArrayQueueEmpty(Q)) 
	{
		ArrayQueueNode *u = dequeueAQ(Q);
		printf("%d\n", u->data);
		curr = pGraph->ppAdjEdge[u->data]->headerNode.pLink;
		while (curr) 
		{
			if (pGraph->visited[curr->data.vertexID] == NOT_VISITED) 
			{
				pGraph->visited[curr->data.vertexID] = VISITED;
				element.data = curr->data.vertexID;
				enqueueAQ(Q, element);
			} 
			curr = curr->pLink;
 		}
	}
}
