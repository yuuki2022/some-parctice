#include <iostream>
#include "Marix.h"

int main() {
	Marix rect(8, 8);
	Marix rect1(8,8);


	rect.insertNode(2, 2, 4);
	rect.insertNode(5, 3, 4);
	rect.insertNode(7, 6, 5);
	rect1.insertNode(10, 2, 4);
	rect1.insertNode(13, 5., 4);

	(rect + rect1).showNozero();
     
	return 0;
}