#include "shortest_path.h"

int main()
{
	LinkedGraph *pGraph = createLinkedGraph(6);

	addVertexLG(pGraph, 0);
	addVertexLG(pGraph, 1);
	addVertexLG(pGraph, 2);
	addVertexLG(pGraph, 3);
	addVertexLG(pGraph, 4);
	addVertexLG(pGraph, 5);

	addEdgewithWeightLG(pGraph, 0, 1, 2);
	addEdgewithWeightLG(pGraph, 0, 3, 1);
	addEdgewithWeightLG(pGraph, 1, 3, 2);
	addEdgewithWeightLG(pGraph, 1, 2, 3);
	addEdgewithWeightLG(pGraph, 3, 4, 1);
	addEdgewithWeightLG(pGraph, 4, 5, 2);
	addEdgewithWeightLG(pGraph, 2, 5, 5);

	// dijkstra
	// int *path = dijkstra(pGraph, 5);
	// for (int i = 0; i < 6; i++)
	// 	printf("[%d] : %d\n", i, path[i]);

	// floyd
	int **path = floyd(pGraph);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
	return 0;
}
