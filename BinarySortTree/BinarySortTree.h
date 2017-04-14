
#ifndef BINARYSORTTREE_H
#define BINARYSORTTREE_H

template <class T>
struct Node{
    Node<T> *left;
    Node<T> *right;
    T data;
};

template <class T>
class BinarySortTree {
private:
    Node<T> *root;
    void Remove_real(const T &data,Node<T> * &b);
    void Inorder_real(Node<T> * &current,void (*visit)(const T &data));//中序遍历某个节点树
public:
    void Inorder(void (*visit)(const T &data)){Inorder_real(root,visit);}//中序遍历某个节点树
    void Insert(const T &data,Node<T> * &n);
    void Create(const T data[], const int n);
    void Remove(const T &data){Remove_real(data,root);}
    void levelPrint();//树按层打印
};


#endif //BINARYSORTTREE_BINARYSORTTREE_H
