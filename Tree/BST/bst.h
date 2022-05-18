#ifndef _BST_
#define _BST_

typedef struct BSTNodeType
{
	int key;
	char data;
    struct BSTNodeType *pRightChild;
    struct BSTNodeType *pLeftChild;
} BSTNode;

typedef struct BSTType
{
    int currentElementCount;
	BSTNode*    RootNode;
} BST;

BST* makeBST(BSTNode rootNode);
BSTNode* createnewNode(BSTNode element);
BSTNode* getRootNodeBST(BST* pBST);
BSTNode* insertChildNodeBST(BST* BST, BSTNode element);
BSTNode* searchNodeBST(BST* BST, int key);
BST* deleteMaxBST(BST* BST);
void preorderTraversalBST(BSTNode* rootNode);
void MaxBSTify(BST* BST, int now);
void displayBST(BST* BST);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#include <stdio.h>
#include <stdlib.h>

#endif