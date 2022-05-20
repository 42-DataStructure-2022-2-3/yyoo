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
	node.key = 47;
	insertChildNodeBST(Tree, node);
	// preorderTraversalBST(Tree->RootNode);

	deleteBSTNode(Tree, 22);
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

BSTNode* searchNodeBST(BST* pBST, int key)
{
	if (!pBST)
		return (NULL);
	BSTNode*	node;

	node = pBST->RootNode;
	while(node && node->key != key)
	{
		if (key < node->key)
			node = node->pLeftChild;
		else if (key > node->key)
			node = node->pRightChild;
		else
			break;
	}
	return (node);
}

BSTNode* searchParentNodeBST(BST* pBST, int key)
{
	BSTNode*	curr = pBST->RootNode;

	if (!pBST || !searchNodeBST(pBST, key))
 	return (NULL);
	while(curr)
	{
		if (key < curr->key)
		{
			if (curr->pLeftChild->key == key)
				break;
			curr = curr->pLeftChild;
		}
		else if (key > curr->key)
		{
			if (curr->pRightChild->key == key)
				break;
			curr = curr->pRightChild;
		}
	}
	return (curr);
}

void deleteBSTNode(BST* pBST, int key)
{
	BSTNode*	node;
	BSTNode*	parent;
	if (!pBST || (node = searchNodeBST(pBST, key)))
		return ;
	parent = searchParentNodeBST(pBST, key);
	if (!node->pLeftChild && !node->pRightChild)
	{
		if (key < parent->key)
		{
			free(parent->pLeftChild);
			parent->pLeftChild = NULL;
		}
		else
		{
			free(parent->pRightChild);
			parent->pRightChild = NULL;
		}
	}
	// else if(node->pLeftChild && node->pRightChild)
	// {

	// }
	else
	{
		if (node->pLeftChild)
		{
			BSTNode*	tmp = node->pLeftChild;
			free(node);
			if (key < parent->key)
				parent->pLeftChild = tmp;
			else
				parent->pRightChild = tmp;
		}
		else if(node->pRightChild)
		{
			BSTNode*	tmp = node->pRightChild;
			free(node);
			if (key < parent->key)
				parent->pRightChild = tmp;
			else
				parent->pRightChild = tmp;
		}
	}

}



void	preorderTraversalBST(BSTNode* rootNode)
{
	printf("%d\n", rootNode->key);
	if (rootNode->pLeftChild)
		preorderTraversalBST(rootNode->pLeftChild);
	if (rootNode->pRightChild)
		preorderTraversalBST(rootNode->pRightChild);
}