#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 

typedef struct StackNodeType
{
	int data;
} StackNode;

typedef struct ArrayStackType
{
	int maxElementCount;
	int currentElementCount;	// ���� ������ ����
	StackNode* pElement;		// Top ����� ������
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, StackNode element);
StackNode* popAS(ArrayStack* pStack);
StackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
