#pragma once
#include "BinaryTreeNode.hpp"
class BinaryTree
{
public: 
	BinaryTreeNode *_tree;
	BinaryTree(int);
	void Add(int);
	void Add(BinaryTreeNode*, int);
	void Add(BinaryTreeNode*, BinaryTreeNode*);
	BinaryTreeNode* Find(BinaryTreeNode* , int);
	bool Remove(int);
	void Output(BinaryTreeNode* , int);
};