#include "arraystack.h"
#include "dfs.h"
#include "graphlinkedlist.h"
#include "heap.h"

#define INF 999999

LinkedGraph *mstKruskal(LinkedGraph *pGraph);
HeapBucket *orderEdge(LinkedGraph *pGraph);
int cyclecheck(LinkedGraph *mst, int fromvertexID, int tovertexID);

LinkedGraph *mstprim(LinkedGraph *pGraph, int startVertexID);
void getminWeightEdge(LinkedGraph *pGraph,LinkedGraph *mst, int fromVertexID, minWeightEdge *minEdge);
int isalready(LinkedGraph *mst, int fromVertexID, int toVertexID);
