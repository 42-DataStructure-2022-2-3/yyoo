#include "linkedstack.h"

int main(void)
{
	LinkedStack *LS;
	LS = createLinkedStack();

	StackNode s01;
	StackNode s02;
	StackNode s03;
	StackNode s04;
	s01.data = 'a';
	s02.data = 'b';
	s03.data = 'c';
	s04.data = 'd';
	pushLS(LS, s01);
	pushLS(LS, s02);
	pushLS(LS, s03);
	pushLS(LS, s04);
	StackNode *curr;
	curr = LS->pTopElement;
	for (int i = 0; i < LS->currentElementCount; i++)
	{
		printf("LS[%d] %c\n", i, curr->data);
		curr = curr->pLink;
	}
	while (LS->pTopElement != NULL)
	{
		curr = LS->pTopElement;
		curr = popLS(LS);
		printf("%c\n", curr->data);
		free(curr);
	}
	deleteLinkedStack(LS);
	system("leaks a.out");
	return (0);
}