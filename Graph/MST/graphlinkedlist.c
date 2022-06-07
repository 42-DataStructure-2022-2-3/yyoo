#include "graphlinkedlist.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));

	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->visited = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList*));
	for (int i = 0; i < maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i] = createLinkedList();
		pGraph->ppAdjEdge[i]->headerNode.data.vertexID = i;
	}
	return (pGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));

	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList*));
	pGraph->visited = (int *)calloc(maxVertexCount, sizeof(int));
	for (int i = 0; i < maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i] = createLinkedList();
		pGraph->ppAdjEdge[i]->headerNode.data.vertexID = i;
	}
	return (pGraph);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
	pGraph = NULL;
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (pGraph && pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)// vertexIndex
{
	if (!pGraph || pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	if (vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int 		last_index;
	ListNode 	element;

	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);

	element.data.weight = 0;
	element.data.vertexID = toVertexID;
	last_index = pGraph->ppAdjEdge[fromVertexID]->currentElementCount;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], last_index, element);
	pGraph->edgecount++;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.data.vertexID = fromVertexID;
		last_index = pGraph->ppAdjEdge[toVertexID]->currentElementCount;
		addLLElement(pGraph->ppAdjEdge[toVertexID], last_index, element);
		pGraph->edgecount++;
	}
	return (SUCCESS);
}
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	int 		last_index;
	ListNode 	element;

	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);

	element.data.weight = weight;
	element.data.vertexID = toVertexID;
	last_index = pGraph->ppAdjEdge[fromVertexID]->currentElementCount;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], last_index, element);
	pGraph->edgecount++;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.data.vertexID = fromVertexID;
		last_index = pGraph->ppAdjEdge[toVertexID]->currentElementCount;
		addLLElement(pGraph->ppAdjEdge[toVertexID], last_index, element);
		pGraph->edgecount++;
	}
	return (SUCCESS);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	return (pGraph->pVertex[vertexID] == USED);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, vertexID) || isEmptyLG(pGraph))
		return(FAIL);
	// clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		removeEdgeLG(pGraph, i, vertexID);
	clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int position;
	ListNode *curr;


	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	if (fromVertexID == toVertexID)
		return (FAIL);
	curr = &pGraph->ppAdjEdge[fromVertexID]->headerNode;
	position = 0;
	while (curr && curr->data.vertexID != toVertexID)
	{
		curr = curr->pLink;
		position++;
	}
	if (position > pGraph->ppAdjEdge[fromVertexID]->currentElementCount)
		return (FAIL);
	// printf("%d\n", position);
	removeLLElement(pGraph->ppAdjEdge[fromVertexID], position);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		curr = &pGraph->ppAdjEdge[toVertexID]->headerNode;
		position = 0;
		while (curr->data.vertexID != fromVertexID)
		{
			curr = curr->pLink;
			position++;
		}
		if (position > pGraph->ppAdjEdge[toVertexID]->currentElementCount)
			return (FAIL);
		removeLLElement(pGraph->ppAdjEdge[toVertexID], position);
	}
	return (SUCCESS);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
		return ;
	printf("maxVertexCount : %d\n", pGraph->maxVertexCount);
	printf("currentVertexCount : %d\n", pGraph->currentVertexCount);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		printf("graphType : GRAPH_UNDIRECTED\n");
	else
		printf("graphType : GRAPH_DIRECTED\n");
	printf("----------------------\n");
	for(int i = 0; i < pGraph->maxVertexCount; i++)
		printf("vertex %d : %d\n", i, pGraph->pVertex[i]);
	printf("----------------------\n");
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("FromVertexID %d : ", i);
		displayLinkedList(pGraph->ppAdjEdge[i]);
		printf("\n");
	}
}
