#include "shortest_path.h"

int **floyd(LinkedGraph *pGraph)
{
	int size = pGraph->maxVertexCount;

	int **path = (int **)calloc(size, sizeof (int *));
	for (int i = 0; i< size; i++)
		path[i] = (int *)calloc(size, sizeof(int));
	// 초기화
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				continue ;
			path[i][j] = INF;
		}
	}

	// 가중치 저장
	for (int i = 0; i < size; i++)
	{
		ListNode *curr = pGraph->ppAdjEdge[i]->headerNode.pLink;
		while (curr)
		{
			path[i][curr->data.vertexID] = curr->data.weight;
			curr = curr->pLink;
		}
	}

	// floyd
	for (int mid = 0; mid < size; mid++)
	{
		for (int start = 0; start < size; start++)
		{
			for (int end = 0; end < size; end++)
			{
				if (path[start][end] > path[start][mid] + path[mid][end])
				{
					path[start][end] = path[start][mid] + path[mid][end];
				}
			}
		}
	}
	return (path);
}
