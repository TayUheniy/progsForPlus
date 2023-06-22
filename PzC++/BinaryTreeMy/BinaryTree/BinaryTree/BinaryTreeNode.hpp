#pragma once

class BinaryTreeNode 
{
public: 
	BinaryTreeNode(BinaryTreeNode *, int );
	~BinaryTreeNode();
	int _value;
	BinaryTreeNode* _parent;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};