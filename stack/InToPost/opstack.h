#ifndef _LINKED_STACK_
#define _LINKED_STACK_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define OPERATOR "()*/+-0"
typedef enum PrecedenceType {lparen, rparen, times, divide, plus, minus, operand} Precedence;
typedef struct StackNodeType
{
	char value;
	Precedence type;
	struct StackNodeType* pLink;
} OpNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	OpNode* pTopElement;
} OpStack;

OpNode* createLinkedStack();
int pushLS(OpStack* pStack, OpNode element);
OpNode* popLS(OpStack* pStack);
OpNode* peekLS(OpStack* pStack);
int checkBracketMatching(char *expression);
void deleteLinkedStack(OpStack* pStack);
int isLinkedStackFull(OpStack* pStack);
int isLinkedStackEmpty(OpStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif