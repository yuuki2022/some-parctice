#include "BiTree.h"
#include <iostream>

int main() {

	BiTree Tree;
	Tree.createTree();
	Tree.createLinkList();
//	std::cout << Tree;
	Tree.Linklisttravse();

	return 0;
}