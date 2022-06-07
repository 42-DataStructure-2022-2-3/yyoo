#include "arraygraph.h"

int main()
{
	ArrayGraph *pGraph = createArrayDirectedGraph(6);

	addVertexAG(pGraph, 0);
	addVertexAG(pGraph, 1);
	addVertexAG(pGraph, 2);
	addVertexAG(pGraph, 3);
	addVertexAG(pGraph, 4);
	addVertexAG(pGraph, 5);

	// addEdgeAG(pGraph, 0, 1);
	// addEdgeAG(pGraph, 0, 2);
	// addEdgeAG(pGraph, 1, 2);
	// addEdgeAG(pGraph, 2, 3);
	// addEdgeAG(pGraph, 3, 4);
	// addEdgeAG(pGraph, 3, 5);
	// addEdgeAG(pGraph, 4, 5);

	addEdgewithWeightAG(pGraph, 0, 1, 4);
	addEdgewithWeightAG(pGraph, 1, 2, 1);
	addEdgewithWeightAG(pGraph, 2, 0, 2);
	addEdgewithWeightAG(pGraph, 2, 1, 3);
	addEdgewithWeightAG(pGraph, 2, 3, 2);
	addEdgewithWeightAG(pGraph, 3, 2, 1);
	addEdgewithWeightAG(pGraph, 3, 4, 1);
	addEdgewithWeightAG(pGraph, 4, 5, 1);
	addEdgewithWeightAG(pGraph, 5, 3, 2);

	// removeVertexAG(pGraph, 0);
	// removeEdgeAG(pGraph, 4, 5);
	displayArrayGraph(pGraph);
	deleteArrayGraph(pGraph);
	return 0;
}
