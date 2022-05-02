#include "linkedstack.h"

int checkBracketMatching(char *expression);

int main(void)
{
	char *str = "{A+B";
	printf("%d\n", checkBracketMatching(str));
	return (0);
}

int checkBracketMatching(char *expression)
{
	LinkedStack *LS;
	StackNode element;
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
				element.data = expression[i];
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
						if (peekLS(LS)->data != '(')
							return (FALSE);
					if (symbol == '}')
					{
						if (peekLS(LS)->data != '{')
							return (FALSE);
					}
					if (symbol == ']')
						if (peekLS(LS)->data != '[')
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