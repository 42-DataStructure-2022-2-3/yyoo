#include "bfs.h"

int main()
{
	LinkedGraph *pGraph = createLinkedGraph(8);

	addVertexAG(pGraph, 0);
	addVertexAG(pGraph, 1);
	addVertexAG(pGraph, 2);
	addVertexAG(pGraph, 3);
	addVertexAG(pGraph, 4);
	addVertexAG(pGraph, 5);
	addVertexAG(pGraph, 6);
	addVertexAG(pGraph, 7);

	addEdgeAG(pGraph, 0, 1);
	addEdgeAG(pGraph, 0, 2);
	addEdgeAG(pGraph, 1, 3);
	addEdgeAG(pGraph, 1, 4);
	addEdgeAG(pGraph, 2, 5);
	addEdgeAG(pGraph, 2, 6);
	addEdgeAG(pGraph, 3, 7);
	addEdgeAG(pGraph, 4, 5);

	// addEdgewithWeightAG(pGraph, 0, 1, 4);
	// addEdgewithWeightAG(pGraph, 1, 2, 1);
	// addEdgewithWeightAG(pGraph, 2, 0, 2);
	// addEdgewithWeightAG(pGraph, 2, 1, 3);
	// addEdgewithWeightAG(pGraph, 2, 3, 2);
	// addEdgewithWeightAG(pGraph, 3, 2, 1);
	// addEdgewithWeightAG(pGraph, 3, 4, 1);
	// addEdgewithWeightAG(pGraph, 4, 5, 1);
	// addEdgewithWeightAG(pGraph, 5, 3, 2);

	traversal_BFS(0, pGraph);
	
	// displayLinkedGraph(pGraph);
	// deleteLinkedGraph(pGraph);
	// system ("leaks a.out");
	return 0;
}
