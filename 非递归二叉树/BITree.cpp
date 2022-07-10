#include "BITree.h"

void BiTree::createTree() {
	char c = '\0';
	std::cin >> c;
	BiNode** ptr = &root;
	if (c != '#') {
		root = new BiNode;
		root->data = c;
		myStack.push(root);
		ptr = &root->leftChild;
	}Q
	int flag = 1;//sign
	
	while ((!myStack.empty()||ptr||flag!=-1)) {
		std::cin >> c;
		if (c != '#') {
			*ptr = new BiNode; 
			(*ptr)->data = c;
			myStack.push(*ptr);
			ptr = &(*ptr)->leftChild;
			++flag;
		}
		else {
			--flag;
			if (flag == -1) {
				break;
			}
			ptr = &myStack.top();          
			ptr = &(* ptr)->rightChild;
			myStack.pop();
		}
	}
}

 BiTree::~BiTree() {
	 BiNode* ptr = root;
	 myStack.push(ptr);
	 ptr = ptr->leftChild;

	 while (!myStack.empty()||ptr) {
		 while (ptr) {
			 myStack.push(ptr);
			 ptr = ptr->leftChild;
		 }
		 ptr = myStack.top();
		 BiNode* p = ptr;
		 myStack.pop();
		 ptr = ptr->rightChild;
		 delete p;
	 }


}
 
 void BiTree::createLinklist(BiNode*& bi){
	 static BiNode* ptr = nullptr;
	 if (!bi) {
		 return;
	}
	 createLinklist(bi->leftChild);
	 if (!bi->leftChild&&!bi->itag) {
		 bi->leftChild = ptr;
		 bi->itag = true;
	 }
	 if (ptr && !ptr->rightChild && !ptr->rtag) {
		 ptr->itag = bi;
		 ptr->rtag = true;
	 }
	 ptr = bi;
	 createLinklist(bi->rightChild);
 }
 

 std::ostream& operator<<(std::ostream& os,  BiTree& bi)
 {
	 BiNode* ptr = bi.root;
	 bi.myStack.push(ptr);
	 ptr = ptr->leftChild;
	 

	 while (!bi.myStack.empty()||ptr) {
		 while (ptr) {
			 bi.myStack.push(ptr);
			 ptr = ptr->leftChild;
		 }
		 if(!bi.myStack.empty()) {
			 ptr = bi.myStack.top();
			 bi.myStack.pop();
			 std::cout << ptr->data << " ";
			 ptr = ptr->rightChild;
		 }
	 }

	 return os;
 }

 BiNode* BiTree::next(BiNode* p) //
 {
	 BiNode* q = nullptr;
	 if (p->rtag) {
		 q = p->rightChild;
	 }
	 else {
		 q = p->rightChild;
		 while (!q->itag) {
			 q = q->leftChild;
		 }
	 }
	 return q;
 }

 void BiTree::Linklisttravse()
 {
	 BiNode* ptr = root;
	 std::cout << std::endl;
	 
	 if (!ptr) {
		 std::cout << "it is an empty tree." << std::endl;
	 }
	 else {
		 while (!ptr->itag) {
			 ptr = ptr->leftChild;
		 }
		 std::cout << ptr->data << " ";
		 while (ptr->rightChild) {
			 ptr = next(ptr);
			 std::cout << ptr->data << " ";
			 }
	 }
 }