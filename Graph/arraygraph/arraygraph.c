#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*pGraph;

	pGraph = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));

	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	for (int i = 0; i < maxVertexCount; i++)
		pGraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
	return (pGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*pGraph;

	pGraph = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));

	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	for (int i = 0; i < maxVertexCount; i++)
		pGraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
	return (pGraph);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
	pGraph = NULL;
}

int isEmptyAG(ArrayGraph* pGraph)
{
	if (pGraph && pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)// vertexIndex
{
	if (!pGraph)
		return (FAIL);
	if (pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	if (vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (SUCCESS);
}
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	return (pGraph->pVertex[vertexID] == USED);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, vertexID) || isEmptyAG(pGraph))
		return(FAIL);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		pGraph->ppAdjEdge[i][vertexID] = 0;
	for (int j = 0; j < pGraph->maxVertexCount; j++)
		pGraph->ppAdjEdge[vertexID][j] = 0;
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	printf("maxVertexCount : %d\n", pGraph->maxVertexCount);
	printf("currentVertexCout : %d\n", pGraph->currentVertexCount);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		printf("graphType : GRAPH_UNDIRECTED\n");
	else
		printf("graphType : GRAPH_DIRECTED\n");
	for(int i = 0; i < pGraph->maxVertexCount; i++)
		printf("vertex %d : %d\n", i, pGraph->pVertex[i]);
	printf("----------------------\n");
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("vertex %d : ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d ", pGraph->ppAdjEdge[i][j]);	
		printf("\n");
	}
}
