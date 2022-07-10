#pragma once
#ifndef _HUFF_H_
#define _HUFF_H_
#include <vector>
#include <cstring>
using pointer = int;
using huffCode = char*;
struct huffTree {
	int value = 0;
	int parent = -1, lchild = -1, rchild = -1;
	bool flag = true;
};
using huff = std::vector<huffTree>;

void selectTarget(std::vector<huffTree>& huff, int& min, int& subMin) {
	
	for (int i = 0; !huff[i].flag; ++i) {
		min = i+1;
	}

	for (int i = 0; i < huff.size(); ++i) {
		if ( huff[min].value> huff[i].value && huff[i].flag) {
			min = i;
		}
	}
	huff[min].flag = false;
	
		for (int i = 0; !huff[i].flag; ++i) {
			subMin = i + 1;
		}
	for (int i = 0; i < huff.size(); ++i) {
		
		if (huff[subMin].value> huff[i].value && huff[i].value>huff[min].value && huff[i].flag) {
			subMin =i;
		}
	}
	
	huff[subMin].flag = false;
}

void buildHuffTree(std::vector<huffTree>& myHuffTree) {
	
	int len = myHuffTree.size();
	for (int i = len; i < 2 * len - 1; i++) {
		int select1 = 0, select2 = 0;
		selectTarget(myHuffTree, select1, select2);
		
		huffTree s1;
		s1.value = myHuffTree[select1].value + myHuffTree[select2].value;
		myHuffTree[select1].parent = myHuffTree.size();
		myHuffTree[select2].parent = myHuffTree.size();
		s1.lchild = select1;
		s1.rchild = select2;
		myHuffTree.push_back(s1);
	}

}

void huffCodeTranslation(huffCode code[],const huff& s1,int n) {
	int n = int(s1.size() / 2.0 + 0.5);
	
	
	for (int pos = 0; pos < n; pos++) {
		int start = n;
		char* temp = new char[start+1];
		code[pos] = new char[n];
		temp[start] = '\0';

		int c = pos;
		while (s1[c].parent != -1) {
			if (s1[s1[c].parent].lchild == c) {
				temp[start - 1] = '0';
			}
			else if (s1[s1[c].parent].rchild == c) {
				temp[start - 1] = '1';
			}
			c = s1[c].parent;
			--start;
		}
			
		for (int i = 0; temp[start+i] != '\0'; ++i) {
			code[pos][i] = temp[start + i];
		}

		++pos;
		delete []temp;
		temp = nullptr;

	}
	

}

#endif // !_HUFF_H_
