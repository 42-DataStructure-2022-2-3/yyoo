#include "arraystack.h"

int main(void)
{
	ArrayStack	*AS;

	AS = createArrayStack(5);
	StackNode s1;
	StackNode s2;
	s1.data = 'a';
	s2.data = 'b';
	pushAS(AS, s1);
	pushAS(AS, s2);
	for (int i = 0; i < AS->currentElementCount; i++)
		printf("AS[%d] %c\n", i, AS->array[i].data);
	StackNode *peek;
	peek = peekAS(AS);
	printf("%c\n", peek->data);
	deleteArrayStack(AS);
	system("leaks a.out");
	return (0);
}