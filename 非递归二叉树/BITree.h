#pragma once
#include <iostream>
#include <stack>
class BiNode {
public:
	char data;
	BiNode* leftChild;
	BiNode* rightChild;
	bool itag;
	bool rtag;
	bool flag;
	BiNode() {
		data = '\0';
		leftChild = nullptr;
		rightChild = nullptr;
		itag = false;
		rtag = false;
		flag = false;
	}		
};

class BiTree
{
private:
	std::stack<BiNode*> myStack;
	BiNode* root;

public:
	BiTree() {
		root = nullptr;
	}
	void createTree();
	void createLinkList() {
		createLinklist(root);
	}
	~BiTree();
	friend std::ostream& operator<<(std::ostream& os, BiTree& bi);
	BiNode* next(BiNode* p);
	void Linklisttravse();
private:
	void createLinklist(BiNode*& bi);
};



