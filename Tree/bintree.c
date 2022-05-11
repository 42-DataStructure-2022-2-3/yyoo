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
	for(int i = 0; i < 4; i++)
	{
		BinTreeNode *curr = getRootNodeBT(Tree);
		while (curr->pLeftChild)
			curr = curr->pLeftChild;
		rootNode.data = 'B' + i;
		insertLeftChildNodeBT(curr, rootNode);
	}
	j = 0;
	for(int i = 0; i < 4; i++)
	{
		BinTreeNode *curr = getRootNodeBT(Tree);
		while (curr->pRightChild)
			curr = curr->pRightChild;
		rootNode.data = 'b' + i;
		insertRightChildNodeBT(curr, rootNode);
	}
	preorderTraversalBinTree(Tree->pRootNode);
	deleteBinTree(Tree);
	free(Tree);
	// printf("%c\n", getRootNodeBT(BT)->data);
	// printf("%c\n", getLeftChildNodeBT(getRootNodeBT(BT))->data);
	// printf("%p\n", getRightChildNodeBT(getRootNodeBT(BT))->pRightChild);
	system("leaks a.out");
	
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

void deleteBinTree(BinTree* pBinTree)
{
	BinTreeNode *curr;

	preorderDeleteBinTree(getRootNodeBT(pBinTree));
	//free(pBinTree);
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

void	preorderTraversalBinTree(BinTreeNode* rootNode)
{
	if (rootNode->pLeftChild)
		preorderTraversalBinTree(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		preorderTraversalBinTree(rootNode->pRightChild);
	printf("%c\n", rootNode->data);
	
}

void	preorderDeleteBinTree(BinTreeNode* rootNode)
{
	if (rootNode->pLeftChild)
		preorderTraversalBinTree(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		preorderTraversalBinTree(rootNode->pRightChild);
	deleteBinTreeNode(rootNode);
}