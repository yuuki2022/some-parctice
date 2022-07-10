#pragma once
#include <iostream>
class Node {
public:
	int member;
	int x=0;
	int y=0;
	Node* right=nullptr;
	Node* down=nullptr;
	Node(const int& num) :
		member(num) {};
	
};


class Marix
{
private:
	int length;
	int width;
	Node** left;
	Node** top;
	int noZeroElem=0;
public:
	explicit Marix(const int& length1 = 0, const int& width1 = 0) :
		length(length1), width(width1) {
		left = new Node * [length];
		for (int i = 0; i < length; ++i) {
			left[i] = new Node(0);
		}
		top = new Node*[width];
		for (int i = 0; i < width; ++i) {
			top[i] = new Node(0);
		}
	};
	~Marix() {
		for (int i = 0; i < length; i++) {
			delete left[i];
		}
		for (int i = 0; i < width; i++) {
			delete top[i];

		}
		delete[]left;
		delete[]top;
	}
	Marix(const Marix& ma);
	bool insertNode(int memeber,int x,int y);
	bool deleteNode(int x,int y);
	int noZeroElemSum()const {
		return noZeroElem;
	}
	friend Marix& operator+(const Marix& Marix1, const Marix& Marix2);
	friend Marix operator*(const Marix& Marix1, const Marix& Marix2);
	void showNozero()const;
	void clearMarix();
	
};




