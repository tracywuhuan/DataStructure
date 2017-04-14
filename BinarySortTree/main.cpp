#include <iostream>
#include <queue>
#include "BinarySortTree.cpp"

template <class T>
void visit(const T &data){
    cout<<data<<"-";
}
int main() {
    BinarySortTree<int> *bstree = new BinarySortTree<int>();
    int data[10] = {2,4,12,43,56,21,55,64,6,3};
    bstree->Create(data,10);
    bstree->Inorder(visit);
    cout<<endl;
    bstree->levelPrint();
    bstree->Remove(2);
    bstree->levelPrint();
    return 0;
}