#include "pch.h"
#include <iostream>

 BinaryTree::BinaryTree(int value) {
	 _tree = new BinaryTreeNode(nullptr, value);
 }

 void BinaryTree::Add(int value) {
	 Add(_tree, value);
 }
 void BinaryTree::Add(BinaryTreeNode* listok, int value) {
	 if (listok->_value > value)
	 {
		 if (listok->_left != nullptr)
			 Add(listok->_left, value);
		 else 
			 new BinaryTreeNode(listok, value);
	 }
	 else
	 {
		 if (listok->_right != nullptr)
			 Add(listok->_right, value);
		 else 
			 new BinaryTreeNode(listok, value);
	 }
 }

 void BinaryTree::Add(BinaryTreeNode* parent, BinaryTreeNode* child) {
	 if (parent->_value > child->_value)  
	 {
		 if (parent->_left != nullptr)
			 Add(parent->_left, child);
		 else {
			 parent->_left = child;
			 child->_parent = parent;
		 }
	 }
	 else
	 {
		 if (parent->_right != nullptr)
			 Add(parent->_right, child);
		 else {
			 parent->_right = child;
			 child->_parent = parent;
		 }
	 }
 }

 BinaryTreeNode* BinaryTree::Find(BinaryTreeNode* listok, int value)
 {
	 if (listok == nullptr) 
		 return nullptr;
	 if (listok->_value == value) 
		 return listok;
	 else 
	 {
		 if (listok->_value > value) 
			 Find(listok->_left, value);
		 else 
			 Find(listok->_right, value);
	 }
 }

 void BinaryTree::Output(BinaryTreeNode* listok, int value)
 {
	 if (listok == nullptr) 
		 return;
	 Output(listok->_right, value + 2);
	 for (int i = 0; i < value; ++i)
		 std::cout << ' ';
	 std::cout << listok->_value << std::endl;
	 Output(listok->_left, value + 2);
 }

 bool BinaryTree::Remove(int value)
 {
	 for (int i = 0; ; ++i) {
		 BinaryTreeNode *delet = this->Find(_tree, value);
		 if (delet != nullptr)
		 {
			 if (delet == _tree)
			 {
				 if (delet->_left != nullptr) {
					 _tree = delet->_left;
					 if (delet->_right != nullptr) 
						 Add(_tree, delet->_right);
				 }
				 else if (delet->_right != nullptr) {
					 _tree = delet->_right;
					 if (delet->_left != nullptr) 
						 Add(_tree, delet->_left);
				 }
				 delet = nullptr;
				 continue;
			 }
			 if (delet->_parent->_left == delet)
			 {
				 delet->_parent->_left = nullptr;
			 }
			 if (delet->_parent->_right == delet)
			 {
				 delet->_parent->_right = nullptr;
			 }
			 if (delet->_left != nullptr)
			 {
				 Add(_tree, delet->_left);
			 }
			 if (delet->_right != nullptr)
			 {
				 Add(_tree, delet->_right);
			 }
			 delet = nullptr;
		 }
		 else 
			 return false;
	 }
	 return true;
 }