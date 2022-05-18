#include "bst.h"

int main()
{
	BSTNode node;
	node.key = 30;
	node.pRightChild = NULL;
	node.pLeftChild = NULL;
	BST* Tree = makeBST(node);

	// printf("%p\n", searchNodeBST(Tree, 18));
	// printf("%p", Tree->RootNode);

	node.key = 20;
	insertChildNodeBST(Tree, node);
	node.key = 40;
	insertChildNodeBST(Tree, node);
	node.key = 10;
	insertChildNodeBST(Tree, node);
	node.key = 24;
	insertChildNodeBST(Tree, node);
	node.key = 34;
	insertChildNodeBST(Tree, node);
	node.key = 6;
	insertChildNodeBST(Tree, node);
	node.key = 46;
	insertChildNodeBST(Tree, node);
	node.key = 14;
	insertChildNodeBST(Tree, node);
	node.key = 22;
	insertChildNodeBST(Tree, node);
	preorderTraversalBST(Tree->RootNode);

}

BST* makeBST(BSTNode rootNode)
{
	BST* Tree = calloc(1, sizeof(BST));
	BSTNode* Node = createnewNode(rootNode);
	Tree->RootNode = Node;
	return (Tree);
}

BSTNode* createnewNode(BSTNode element)
{
	BSTNode*    newNode;

	newNode = (BSTNode*)calloc(1, sizeof(BSTNode));
	*newNode = element;
	return (newNode);
}

BSTNode* getRootNodeBST(BST* pBST)
{
	if (!pBST)
		return (NULL);
	return (pBST->RootNode);
}


BSTNode* searchNodeBST(BST* pBST, int key)
{
	if (!pBST)
		return (NULL);
	BSTNode*	node;

	node = pBST->RootNode;
	while(node && node->key != key)
	{
		if (key < node->key)
		{
			node = node->pLeftChild;
		}
		else if (key > node->key)
		{
			node = node->pRightChild;
		}
		else
			break;
	}
	return (node);
}

BSTNode* insertChildNodeBST(BST* pBST, BSTNode element)
{
	BSTNode* new_node = createnewNode(element);
	BSTNode* curr = pBST->RootNode;

	if(searchNodeBST(pBST, new_node->key))
		return (NULL);
	while(curr && curr->key != new_node->key)
	{
		if (new_node->key < curr->key)
		{
			if (curr->pLeftChild == NULL)
			{
				curr->pLeftChild = new_node;
				break ;
			}
			curr = curr->pLeftChild;
		}
		else if (new_node->key > curr->key)
		{
			if (curr->pRightChild == NULL)
			{
				curr->pRightChild = new_node;
				break ;
			}
			curr = curr->pRightChild;
		}
	}
	return (new_node);
}

void	preorderTraversalBST(BSTNode* rootNode)
{
	printf("%d\n", rootNode->key);
	if (rootNode->pLeftChild)
		preorderTraversalBST(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		preorderTraversalBST(rootNode->pRightChild);
}