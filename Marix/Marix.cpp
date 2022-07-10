#include "Marix.h"
#include <iostream>

Marix& operator+(const Marix& Marix1, const Marix& Marix2){
	if (Marix1.length != Marix2.length || Marix2.width != Marix1.width) {
		std::cout << "can't add!!";
		abort();
	}

	Marix resultMarix(Marix1.length,Marix1.width);

	for (int i = 0; i < Marix1.length; ++i) {
		Node* pointer = Marix1.left[i]->right;
		if (pointer) {
			resultMarix.insertNode(pointer->member, pointer->x, pointer->y);
			pointer = pointer->right;
		}
		else {
			continue;
		}
		
	}
for (int i = 0; i < Marix2.length; ++i) {
		Node* p = Marix2.left[i]->right;
		Node* pointerResult = resultMarix.left[i]->right;

		while (p && pointerResult) {
			if (p->x < pointerResult->x) {
				resultMarix.insertNode(p->member, p->x, p->y);
			}
			else if (p->x == pointerResult->x || p->y == pointerResult->y) {
				pointerResult->member = pointerResult->member + p->member;

			}
			else  {
				pointerResult = pointerResult->right;
				continue;
			}

			p = p->right;
			pointerResult = pointerResult->right;
		}
		if (!pointerResult&&p) {
			while (p) {
				resultMarix.insertNode(p->member, p->x, p->y);
				p = p->right;
			}
		}
		
	}

	resultMarix.showNozero();

	return resultMarix;
}
Marix operator*(const Marix& Marix1, const Marix& Marix2) {
	if (Marix1.length != Marix2.width || Marix2.length != Marix1.width) {
		std::cout << "can't multiply!!";
		abort();
	}
	Marix resultMarix(Marix1.length, Marix2.width);

	
}


bool Marix::insertNode(int member,int x,int y) {
	Node* node = new Node(member);
	Node* p = left[x - 1]->right;
	Node* ptr = left[x - 1];

	while (p) {
		if(p->x==x&&p->y==y){
			break;
		}
		p = p->right;
	}
	if (p) {
		std::cout << "Your target point has been occupied!!!" << std::endl;
		return false;
	}
	
	p = left[x - 1]->right;
	node->x = x;
	node->y = y;
	
	while (p && p->x < node->x) {
		p = p->right;
		ptr = ptr->right;
	}
	ptr->right = node;
	node->right = p; //ºáÖáÁ´½Ó

	Node* p1 = top[y - 1]->down;
	Node* ptr1 = top[y - 1];

	while (p1&&p1->y<node->y) {
		p1 = p1->down;
		ptr1 = ptr1->down;
	}
	ptr1->down = node;
	node->down = p1;
	
	noZeroElem++;
	return true;
}

bool Marix::deleteNode(int x, int y)
{
	Node* p = left[x - 1]->right;
	Node* ptr = left[x-1];
	Node* p1 = top[y - 1]->down;
	Node* ptr1 = top[y - 1];

	while (p && p->x < x){
		p = p->right;
		ptr = ptr->right;
	}

	if (!p||p->x > x) {
		std::cout << "Oh!the node you want to delete is empty" << std::endl;
		return false;
	}
	
	while (p1 && p1->y < y) {
		p1 = p1->down;
		ptr1 = ptr1->down;
	}
	if (!p1||p1->y > y) {
		std::cout << "Oh!the node you want to delete is empty" << std::endl;
		return false;
	}

	noZeroElem--;
	ptr->right = p->right;
	ptr1->down = p1->down;
	delete p;
	return true;
}

void Marix::showNozero()const {
	for (int i = 0; i < length; ++i) {
		Node* pointer = left[i]->right;
		while (pointer) {
			std::cout << "(" << pointer->x << " , " << pointer->y <<", "<<pointer->member<<")"<< std::endl;
			pointer = pointer->right;
		}
	}

	std::cout << "the total Nozeroelem:" << noZeroElem;
}

void Marix::clearMarix()
{
	for (int i = 0; i < length; ++i) {
		Node* pointer = left[i];
		while (pointer) {
			Node* ptr = pointer;
			pointer = pointer->right;
			delete[]ptr;
		}
	}
}

Marix::Marix(const Marix& ma) {
	length = ma.length;
	width = ma.width;

	left = new Node * [length];
	for (int i = 0; i < length; ++i) {
		left[i] = new Node(0);
	}
	top = new Node * [width];
	for (int i = 0; i < width; ++i) {
		top[i] = new Node(0);
	}

	for (int i = 0; i < length; ++i) {
		Node* pointer = ma.left[i];
		while (pointer) {
			this->insertNode(pointer->member, pointer->x, pointer->y);
		}
	}
}

