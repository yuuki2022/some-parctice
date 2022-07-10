#include <iostream>
#include <vector>
#include "huff.h"



int main() {
	huff test;
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; ++i) {
		huffTree sample;
		std::cin >> sample.value;
		test.push_back(sample);
	}
	buildHuffTree(test);

	for (int i = 0; i < test.size(); ++i) {
		std::cout << test[i].value << " " << test[i].parent << " " << test[i].lchild << " " << test[i].rchild << std::endl;
	}

	huffCode* myCode=nullptr;

	huffCodeTranslation(myCode, test);



}