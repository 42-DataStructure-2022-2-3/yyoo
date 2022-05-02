#include "opstack.h"

void	crete_push(LinkedStack *pStack, char value, Precedence type)
{
	StackNode newNode;
	newNode.value = value;
	newNode.type = type;
	pushLS(pStack, newNode);
}

int	pop_higher_priority(LinkedStack *pStack, Precedence priority)
{
	StackNode	*check;

	check = pStack->pTopElement;
	while (pStack->currentElementCount != 0 && check != NULL)
	{
		if (check->type < priority)
			printf("%c ", OPERATOR[popLS(pStack)->type]);
		check = check->pLink;
	}
	return (0);
}

int	main(void)
{
	LinkedStack *LS = createLinkedStack();
	int	i = -1;
	char *str = "a * b + c";

	if (!checkBracketMatching(str))
	{
		printf("[ERROR] Wrong String\n");
		return (0);
	}
	while (str[++i])
	{
		if (str[i] == 32)
			continue ;
		else if (!strchr(OPERATOR, str[i]))
			printf("%c", str[i]);
		else
		{
			if (str[i] == '(')
				crete_push(LS, str[i], 0);
			else if (str[i] == ')')
			{
				StackNode	*curr;
				curr = LS->pTopElement;
				while (curr->type != 0)
					printf("%c", OPERATOR[popLS(LS)->type]);
				if (curr->type == 0)
					popLS(LS);
			}
			else if (str[i] == '*')
			{
				StackNode	*curr;
				curr = LS->pTopElement;
				if (!isLinkedStackEmpty(LS) && curr->type < 2)
					popLS(LS);
				else
					crete_push(LS, str[i], 2);
			}
			else if (str[i] == '/')
			{
				StackNode	*curr;
				curr = LS->pTopElement;
				if (!isLinkedStackEmpty(LS) && curr->type < 2)
					popLS(LS);
				else
					crete_push(LS, str[i], 3);
			}
			else if (str[i] == '+')
			{
				StackNode	*curr;
				curr = LS->pTopElement;
				if (!isLinkedStackEmpty(LS) && curr->type < 4)
					popLS(LS);
				else
					crete_push(LS, str[i], 4);
			}
			else if (str[i] == '-')
			{
				StackNode	*curr;
				curr = LS->pTopElement;
				if (!isLinkedStackEmpty(LS) && curr->type < 4)
					popLS(LS);
				else
					crete_push(LS, str[i], 5);
			}
		}
	}
	if (!isLinkedStackEmpty(LS))
		while (LS->currentElementCount > 0)
			printf("%c", OPERATOR[popLS(LS)->type]);
	return (TRUE);
}
