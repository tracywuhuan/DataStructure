#include <iostream>
#include "AVLTree.cpp"

#define N 12

int main() {
    AVLTree<int> *avltree = new AVLTree<int>();
    avltree->makeEmpty(avltree->tree);
    int i;
    int j = 0;
    for (i = 0; i < N; i++, j = (j + 2) % 50) {
        cout << "insert:" << j << endl;
        avltree->tree = avltree->Insert(j, avltree->tree);
    }
    for (i = 0; i < N; i += 2) {
        cout << "delete:" << i << endl;
        avltree->tree = avltree->Delete(i, avltree->tree);
    }
    avltree->levelPrint();

    return 0;
}