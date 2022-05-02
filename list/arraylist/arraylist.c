#include "arraylist.h"

int	main()
{
	ArrayList	*List;
	ArrayListNode A;

	A.data = 3;
	List = createArrayList(10);
	int i = 0;
	/*
	while (i < 8)
	{
		List->pElement[i].data = i;
		List->currentElementCount++;
		i++;
	}
	*/
	displayArrayList(List);
	//printf("===================================\n");
	//removeALElement(List, 3);
	//displayArrayList(List);
}

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *pList;

	pList = NULL;
	if (maxElementCount > 0)
	{
		if (!pList = malloc(sizeof(ArrayList)))
			return (NULL);
		pList->maxElementCount = maxElementCount;
		pList->currentElementCount = 0;
		pList->pElement = (ArrayListNode *)calloc(maxElementCount, sizeof(ArrayListNode));
	}
	return (pList);
}

void clearArrayList(ArrayList* pList)
{
	pList->currentElementCount = 0;
	memset(pList->pElement, 0, pList->maxElementCount);
}

int isArrayListFull(ArrayList* pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (1);
	return (0);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int idx;

	if (!isArrayListFull(pList) && position >=0 && position <= pList->currentElementCount)
	{
		idx = pList->currentElementCount;
		while (idx > position)
		{
			pList->pElement[idx] = pList->pElement[idx - 1];
			idx--;
		}
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
		return (1);
	}
	return (0);
}

int removeALElement(ArrayList* pList, int position)
{
	int idx;

	if (position >= 0 && position < pList->currentElementCount)
	{
		idx = position;
		while (idx < pList->currentElementCount - 1)
		{
			pList->pElement[idx] = pList->pElement[idx + 1];
			idx++;
		}
		pList->currentElementCount--;
		return (1);
	}
	return (0);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (position >= 0 && position < pList->currentElementCount)
		return (&pList->pElement[position]);
	else
		return (NULL);
}

void displayArrayList(ArrayList* pList)
{
	int idx;

	printf("maxElementCount : %d\n", pList->maxElementCount);
	printf("currentElementCount : %d\n", pList->currentElementCount);
	idx = 0;
	while (idx < pList->currentElementCount)
	{
		printf("pElement[%d] : %d\n", idx, pList->pElement[idx].data);
		idx++;
	}
}
void deleteArrayList(ArrayList* pList)
{
	clearArrayList(pList);
	free(pList->pElement);
	free(pList);
	pList = NULL;
}

int getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}
