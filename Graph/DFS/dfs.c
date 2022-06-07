#include "dfs.h"

void recur_traversal_DFS(int vertexID, LinkedGraph *pGraph)
{ 
	ListNode *curr;
	int		next;
	
	if (pGraph->visited[vertexID] == VISITED)
		return ;
	pGraph->visited[vertexID] = VISITED;
	printf("%d\n", vertexID);
	curr = &pGraph->ppAdjEdge[vertexID]->headerNode;
	while (curr)
	{
		next = curr->data.vertexID;
		if(!pGraph->visited[next])
			recur_traversal_DFS(next, pGraph);
		curr = curr->pLink;
	}
}

void	traversal_DFS (int vertexID, LinkedGraph *pGraph) 
{
	int		next;
	ListNode	*curr;
	ArrayStack	*pStack;
	StackNode	element;

	pStack = createArrayStack(pGraph->maxVertexCount);
	pGraph->visited[vertexID] = VISITED;
	element.data = vertexID;
	pushAS(pStack, element);
	while(!isArrayStackEmpty(pStack)) 
	{
		StackNode *u = popAS(pStack);
		printf("%d\n", u->data);
		vertexID = u->data;
		curr = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
		while (curr)
		{ 
			 if (pGraph->visited[curr->data.vertexID] == NOT_VISITED)
	 		{
				pGraph->visited[curr->data.vertexID] = VISITED;
				element.data = curr->data.vertexID;
				pushAS(pStack, element);
			}
			curr = curr->pLink;
		}
	}

}



