#include "pch.h"
#include <iostream>

BinaryTreeNode::BinaryTreeNode(BinaryTreeNode *listok, int value)
{
	_value = value;
	if (listok != nullptr) {
		if (listok->_value > this->_value) {
			listok->_left = this;
		}
		else
		{
			listok->_right = this;
		}
		_parent = listok;
	}
	_right = nullptr;
	_left = nullptr;
}

BinaryTreeNode::~BinaryTreeNode()
{
	delete _right;
	delete _left;
}
