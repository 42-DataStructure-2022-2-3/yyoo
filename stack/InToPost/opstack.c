#include "opstack.h"

int checkBracketMatching(char *expression)
{
	LinkedStack *LS;
	OpNode element;
	char symbol;
	int i = 0;

	LS = createLinkedStack();
	while (expression[i])
	{
		symbol = expression[i];
		switch(symbol)
		{
			case '(':
			case '[':
			case '{':
			{
				element.value = expression[i];
				pushLS(LS, element);
				break;
			}
			case ')':
			case '}':
			case ']':
			{
				if (isLinkedStackEmpty(LS))
					return (FALSE);
				else{
					if (symbol == ')')
						if (peekLS(LS)->value != '(')
							return (FALSE);
					if (symbol == '}')
					{
						if (peekLS(LS)->value != '{')
							return (FALSE);
					}
					if (symbol == ']')
						if (peekLS(LS)->value != '[')
							return (FALSE);
					popLS(LS);
				}
			}
		}
		i++;
	}
	if (!isLinkedStackEmpty(LS))
		return (FALSE);
	deleteLinkedStack(LS);
	return (TRUE);
}

OpNode* createLinkedStack()
{
	OpStack *newLS;

	newLS = (OpNode *)calloc(1, sizeof(OpNode));
	newLS->pTopElement = NULL;
	return (newLS);
}

int	pushLS(OpStack* pStack, OpNode element)
{
	OpNode *newNode;

	newNode = (OpNode *)calloc(1, sizeof(OpNode));
	*newNode = element;
	if (pStack->pTopElement == NULL)
		pStack->pTopElement = newNode;
	else
	{
		newNode->pLink = pStack->pTopElement;
		pStack->pTopElement = newNode;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

OpNode* popLS(OpStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	OpNode	*popNode;
	popNode = pStack->pTopElement;
	pStack->pTopElement = popNode->pLink;
	--(pStack->currentElementCount);
	return (popNode);
}

OpNode* peekLS(OpStack* pStack)
{
	return (pStack->pTopElement);
}

void deleteLinkedStack(OpStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return ;

	OpNode	*delNode;

	while (pStack->pTopElement)
	{
		delNode = popLS(pStack);
		free(delNode);
		--(pStack->currentElementCount);
	}
	free(pStack);
}

int isLinkedStackFull(OpStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(OpStack* pStack)
{
	return (pStack->pTopElement == NULL);
}