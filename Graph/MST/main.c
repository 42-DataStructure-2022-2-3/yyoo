#include "mst.h"

int main()
{
	LinkedGraph *pGraph = createLinkedGraph(6);

	addVertexLG(pGraph, 0);
	addVertexLG(pGraph, 1);
	addVertexLG(pGraph, 2);
	addVertexLG(pGraph, 3);
	addVertexLG(pGraph, 4);
	addVertexLG(pGraph, 5);

	addEdgewithWeightLG(pGraph, 0, 1, 4);
	addEdgewithWeightLG(pGraph, 0, 2, 3);
	addEdgewithWeightLG(pGraph, 1, 2, 2);
	addEdgewithWeightLG(pGraph, 2, 3, 1);
	addEdgewithWeightLG(pGraph, 3, 4, 1);
	addEdgewithWeightLG(pGraph, 3, 5, 5);
	addEdgewithWeightLG(pGraph, 4, 5, 6);

	LinkedGraph *mst = mstKruskal(pGraph);
	displayLinkedGraph(mst);
	return 0;
}
