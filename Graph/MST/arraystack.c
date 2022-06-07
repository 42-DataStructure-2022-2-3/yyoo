#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack	*stack;
	stack = (ArrayStack *)calloc(1, sizeof(ArrayStack));
	if (stack)
	{
		stack->maxElementCount = maxElementCount;
		stack->pElement = (StackNode *)calloc(stack->maxElementCount, sizeof(StackNode));
		if (!stack->pElement)
			return (NULL);
	}
	else
		return (NULL);
	return (stack);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
	// StackNode	*pnode;

	if (isArrayStackFull(pStack))
		return (FALSE);
	// pnode = (StackNode *)calloc(1, sizeof(StackNode));
	// pnode->data = element.data;
	pStack->pElement[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
	StackNode	*popnode;
	StackNode	*copynode;

	if (isArrayStackEmpty(pStack))
		return (NULL);
	copynode = (StackNode *)calloc(1, sizeof(StackNode));
	popnode = &pStack->pElement[pStack->currentElementCount - 1];
	*copynode = *popnode; // 수정 필요
	bzero(popnode, sizeof(StackNode)); // bzero표준이 아님 memset추천! 표준보면서 공부
	pStack->currentElementCount--;
	return (copynode);
}

StackNode* peekAS(ArrayStack* pStack)
{
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack* pStack)
{
	free(pStack->pElement);
	bzero(pStack, sizeof(ArrayStack));
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	return (pStack->maxElementCount == pStack->currentElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	return (pStack->currentElementCount == 0);
}