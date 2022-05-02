#include "arraystack.h"

ArrayStack* createArrayStack(int max)
{
	ArrayStack 	*newAS;
	StackNode	*arr;

	newAS = (ArrayStack *)calloc(1, sizeof(ArrayStack));
	arr = (StackNode *)calloc(max, sizeof(StackNode));
	newAS->maxElementCount = max;
	newAS->array = arr;
	return (newAS);
}

int pushAS(ArrayStack *pStack, StackNode element)
{
	if (isArrayStackFull(pStack))
	{
		printf("[ERROR]Stack is Full!\n");
		return (FALSE);
	}
	else
	{
		pStack->array[pStack->currentElementCount] = element;
		pStack->currentElementCount++;
		return (TRUE);
	}
}

StackNode* popAS(ArrayStack *pStack)
{
	StackNode *popNode;

	if (isArrayStackEmpty(pStack))
		return (NULL);
	popNode = &pStack->array[pStack->currentElementCount - 1];
	--(pStack->currentElementCount);
	return (popNode);
}

StackNode* peekAS(ArrayStack *pStack)
{
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (&pStack->array[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack *pStack)
{
	free(pStack->array);
	free(pStack);
}

int isArrayStackFull(ArrayStack *pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack *pStack)
{
	return (pStack->currentElementCount == 0);
}