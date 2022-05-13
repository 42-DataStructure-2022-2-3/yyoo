#include "bintree.h"

int main()
{
	BinTreeNode rootNode;
	rootNode.data = 'A';
	rootNode.visited = 0;
	rootNode.pLeftChild = NULL;
	rootNode.pRightChild = NULL;
	BinTree*	Tree = makeBinTree(rootNode);

	int j = 0;
	// insertLeftChildNodeBT(getRootNodeBT(Tree), rootNode);
	for(int i = 0; i < 8; i++)
	{
		BinTreeNode *curr = getRootNodeBT(Tree);
		while (curr->pLeftChild)
			curr = curr->pLeftChild;
		rootNode.data = 'B' + i;
		insertLeftChildNodeBT(curr, rootNode);
		i++;
		rootNode.data = 'B' + i;
		insertRightChildNodeBT(curr, rootNode);
	}
	// j = 0;
	// for(int i = 0; i < 4; i++)
	// {
	// 	BinTreeNode *curr = getRootNodeBT(Tree);
	// 	while (curr->pRightChild)
	// 		curr = curr->pRightChild;
	// 	rootNode.data = 'b' + i;
	// 	insertRightChildNodeBT(curr, rootNode);
	// }

	//                A
	//		     B        C
	//       D      E
	//   F     G
	//H    I
	printf("-----전위 순회------\n");
	preorderTraversalBinTree(Tree->pRootNode);
	printf("-----중위 순회------\n");
	inorderTraversalBinTree(Tree->pRootNode);
	printf("-----후위 순회------\n");
	postorderTraversalBinTree(Tree->pRootNode);

	Tree = deleteBinTree(Tree);
	printf("%p", Tree);
	// free(Tree);
	// system("leaks a.out");
	
	return 0;
}

BinTreeNode* createnewNode(BinTreeNode element)
{
	BinTreeNode*    newNode;

	newNode = (BinTreeNode*)calloc(1, sizeof(BinTreeNode));
	*newNode = element;
	return (newNode);
}

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree*    Tree;

	Tree = (BinTree*)calloc(1, sizeof(BinTree));
	Tree->pRootNode = createnewNode(rootNode);
	return (Tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if(!pParentNode || pParentNode->pLeftChild)
		return (NULL);
	pParentNode->pLeftChild = createnewNode(element);
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if(!pParentNode || pParentNode->pRightChild)
		return (NULL);
	pParentNode->pRightChild = createnewNode(element);
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pRightChild);
}

BinTree* deleteBinTree(BinTree* pBinTree)
{
	BinTreeNode *curr;

	preorderDeleteBinTree(getRootNodeBT(pBinTree));
	free(pBinTree);
	return (NULL);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode->pLeftChild || pNode->pRightChild)
	{
		printf("err\n");
		return ;
	}
	free(pNode);
	pNode = NULL;
}

void	postorderTraversalBinTree(BinTreeNode* rootNode)
{
	if (rootNode->pLeftChild)
		postorderTraversalBinTree(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		postorderTraversalBinTree(rootNode->pRightChild);
	rootNode->visited = 1;
	printf("%c\n", rootNode->data);
}

void	preorderTraversalBinTree(BinTreeNode* rootNode)
{
	rootNode->visited = 1;
	printf("%c\n", rootNode->data);
	if (rootNode->pLeftChild)
		preorderTraversalBinTree(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		preorderTraversalBinTree(rootNode->pRightChild);
}
void	inorderTraversalBinTree(BinTreeNode* rootNode)
{
	if (rootNode->pLeftChild)
		inorderTraversalBinTree(rootNode->pLeftChild);
	rootNode->visited = 1;
	printf("%c\n", rootNode->data);
	if (rootNode->pRightChild)
		inorderTraversalBinTree(rootNode->pRightChild);
}

void	preorderDeleteBinTree(BinTreeNode* rootNode)
{
	if (rootNode->pLeftChild)
		preorderDeleteBinTree(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		preorderDeleteBinTree(rootNode->pRightChild);
	free(rootNode);
}