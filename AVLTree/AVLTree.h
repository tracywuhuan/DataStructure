
#ifndef AVLTREE_H
#define AVLTREE_H

template<class T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    int height = 0;
};

template<class T>
class AVLTree {
public:
    Node<T> *tree;

    Node<T> *makeEmpty(Node<T> *);

    Node<T> *find(T data, Node<T> *n);

    void Create(const T data[], const int n);

    Node<T> *Insert(T data, Node<T> *n);

    Node<T> *Delete(T data, Node<T> *n);

    void levelPrint();
};

#endif //AVLTREE_H
