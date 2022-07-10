#include <iostream>
#include "BStree.h"

int main()
{
    while (true) {
        BSTree sequence;
        sequence.createBSTree();

        sequence.showTree();

        int num = 0;
        /*std::cin >> num;
        sequence.destroy(num);
        sequence.showTree();

        std::cin >> num;
        sequence.InsertBSTree(num);
        sequence.showTree();*/

        std::cin >> num;
        std::cout << sequence.searchBSTree(num);
    }

    return 0;
}

