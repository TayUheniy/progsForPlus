#include "pch.h"
#include "BinaryTree.hpp"
#include "BinaryTreeNode.hpp"


int main() {
	BinaryTree tr = BinaryTree(5);
	tr.Add(2);
	tr.Add(1);
	tr.Add(4);
	tr.Add(4);
	tr.Add(3);
	tr.Add(7);
	tr.Add(6);
	tr.Add(8);
	tr.Output(tr._tree, 0);
	return 0;
}
