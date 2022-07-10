#pragma once

class Data{
public:
	int data;
	Data* leftchild;
	Data* rightchild;
	int loseBalance;
	Data() {
		data = 0;
		leftchild = nullptr;
		rightchild = nullptr;
		loseBalance = 0;
	}
};

class BSTree  
{
private:
	Data* root;
public:
	BSTree() :
		root(nullptr) {};

	void createBSTree();
	void InsertBSTree(const int insert);
	bool searchBSTree(const int target);
	void showTree();
	void destroy(const int target);
	~BSTree();

protected:
	void InsertBSTree(Data*& , int target);
	bool searchBSTree(Data*, int target);
	void showTree(Data*);
	int depth(Data*);
};

