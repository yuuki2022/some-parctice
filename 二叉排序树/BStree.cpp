#include "BStree.h"
#include <iostream>
#include <stack>

constexpr auto DeadLine = 404;
using namespace std;

using enter = int;

void BSTree::createBSTree()
{
	root = new Data;
	cin >> root->data;

	enter newNumber = 0;
	
	while (cin >> newNumber && newNumber != DeadLine) {
		InsertBSTree(newNumber);
	}
	
}

void BSTree::InsertBSTree(const int insert)
{
	InsertBSTree(root, insert);
}

void BSTree::destroy(const int target)
{
	Data* p = root;
	Data* f = nullptr;
	while (p) {
		if (p->data == target) {
			break;
		}
		else if (p->data > target) {
			f = p;
			p = p->leftchild;
		}
		else if (p->data < target) {
			f = p;
			p = p->rightchild;
		}
	}

	if (p == root) {
		Data* s = p->leftchild;
		while (s->rightchild) {
			s = s->rightchild;
		}

		s->rightchild = p->rightchild;

		root = p->leftchild;
		delete p;
		p = nullptr;
		return;
	}

	if (!p) {
		std::cout << "There exits no data you want to data" << std::endl;
		return;
	}
	Data* ptr = p;

	if (p->leftchild && p->rightchild) {
		Data* s = p->leftchild;
		
		while (s->rightchild) {
			ptr = s;
			s = s->rightchild;
		}

		p->data = s->data;

		if (p != ptr) {
			ptr->rightchild = s->leftchild;
		}
		else {
			ptr->leftchild = s->leftchild;
		}

		delete s;
		return;
	}
	else if (!p->leftchild&&p->rightchild) {
		f->rightchild = p->rightchild;
		delete p;
	}
	else if (p->leftchild && !p->rightchild){
		f->leftchild = p->leftchild;
		delete p;
	}
	else{
		if (f->leftchild == p) {
			f->leftchild = nullptr;
			delete p;
			p = nullptr;
		}
		else if (f->rightchild == p) {
			f->rightchild = nullptr;
			delete p;
			p = nullptr;
	}
	}

	
}

bool BSTree::searchBSTree(const int target)
{
	return searchBSTree(root,target);
}

BSTree::~BSTree() {
	using std::stack;
	stack<Data*> myStack;

	myStack.push(root);

	while (!myStack.empty()) {
		Data* node = myStack.top();
		myStack.pop();

		if (node->leftchild) {
			myStack.push(node->leftchild);
		}
		else if (node->rightchild) {
			myStack.push(node->rightchild);
		}

		delete node;
	}

}
void BSTree::showTree() {
	std::cout << " here is sequence" << std::endl;
	showTree(root);
	std::cout << std::endl;
}

void BSTree::InsertBSTree(Data*& node, int target)
{
	if (!node) {
		node = new Data;
		node->data = target;
		return;
	}
	else if (node->data >= target) {
		InsertBSTree(node->leftchild, target);
	}
	else if (node->data < target) {
		InsertBSTree(node->rightchild,target);
	}

}

bool BSTree::searchBSTree(Data* node, int target)
{
	if (!node) {
		return false;
	}
	else if (node->data == target) {
		return true;
	}
	else if (node->data > target) {
		return searchBSTree(node->leftchild, target);
	}
	else if(node->data < target) {
		return searchBSTree(node->rightchild, target);
	}
}

void BSTree::showTree(Data* node) {
	if (!node) {
		return;
	}
	else {
		showTree(node->leftchild);
		std::cout << node->data << " ";
		showTree(node->rightchild);
	}
}



