
#include "AVLTree.h"
#include <iostream>
#include <queue>

using namespace std;

template<class T>
Node<T> *AVLTree<T>::makeEmpty(Node<T> *n) {
    if (n != NULL) {
        makeEmpty(n->left);
        makeEmpty(n->right);
        free(n);
    }
    return NULL;
}

template<class T>
inline int getHeight(Node<T> *n) {
    if (n != NULL) {
        return n->height;
    } else {
        return -1;
    }
}

template<class T>
inline T Max(T a, T b) {
    return a > b ? a : b;
}

template<class T>
Node<T> *LL(Node<T> *root) {
    Node<T> *pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;
    root->height = Max(getHeight(root->left), getHeight(root->right)) + 1;
    pivot->height = Max(getHeight(pivot->left), getHeight(pivot->right)) + 1;
    return pivot;
}

template<class T>
Node<T> *RR(Node<T> *root) {
    Node<T> *pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
    root->height = Max(getHeight(root->left), getHeight(root->right)) + 1;
    pivot->height = Max(getHeight(pivot->left), getHeight(pivot->right)) + 1;
    return pivot;
}

template<class T>
Node<T> *LR(Node<T> *root) {
    root->left = RR(root->left);
    return LL(root);
}

template<class T>
Node<T> *RL(Node<T> *root) {
    root->right = LL(root->right);
    return RR(root);
}

template<class T>
Node<T> *rotate(Node<T> *n) {
    if (getHeight(n->left) - getHeight(n->right) == 2) {
        if (getHeight(n->left->left) >= getHeight(n->left->right))
            n = LL(n);  // LL旋转
        else
            n = LR(n);     // LR旋转
    }
    if (getHeight(n->right) - getHeight(n->left) == 2) {
        if (getHeight(n->right->right) >= getHeight(n->right->left))
            n = RR(n);  // RR旋转
        else
            n = RL(n);     // RL旋转
    }
    return n;
}

template<class T>
void AVLTree<T>::Create(const T data[], const int n)         //由数组创建二叉排序树，n是数组大小
{
    for (int i = 0; i < n; i++) {
        tree = Insert(data[i], tree);
    }
}

template<class T>
Node<T> *AVLTree<T>::Insert(T data, Node<T> *n) {
    if (n == NULL) {
        n = new Node<T>;
        n->left = n->right = NULL;
        n->data = data;
        n->height = 0;
    } else if (data < n->data) {//插入到了左子树
        n->left = Insert(data, n->left);
        if (getHeight(n->left) - getHeight(n->right) == 2) {//需要调整
            if (data < n->left->data) {//插入到了左子树的左边
                n = LL(n);//LL rotate
            } else {//左子树的右边
                n = LR(n);//LR rotate
            }
        }
    } else {
        n->right = Insert(data, n->right);
        if (getHeight(n->right) - getHeight(n->left) == 2) {//需要调整
            if (data > n->right->data) {//右子树的右边
                n = RR(n);//RR rotate
            } else {//右子树的左边
                n = RL(n);//RL rotate
            }
        }
    }
    n->height = Max(getHeight(n->left), getHeight(n->right)) + 1;
    return n;
}

template<class T>
Node<T> *AVLTree<T>::Delete(T data, Node<T> *n) {
    if (n == NULL) {
        return NULL;
    }
    if (data == n->data) {//find data
        if (n->right == NULL) {//节点右子树为null，直接将左子树提上来
            Node<T> *tmp = n;
            n = n->left;
            delete tmp;
        } else {//右子树不为null，找到右子树中最小的值代替当前节点
            Node<T> *tmp = n->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            n->data = tmp->data;
            n->right = Delete(n->data, n->right);
            n->height = Max(getHeight(n->left), getHeight(n->right)) + 1;
        }
    } else if (data < n->data) {
        n->left = Delete(data, n->left);
    } else {
        n->right = Delete(data, n->right);
    }
    /*
    *   当删除元素后调整平衡
    */
    if (n != NULL) {
        n->height = Max(getHeight(n->left), getHeight(n->right)) + 1;
        if (n->left != NULL)
            n->left = rotate(n->left);
        if (n->right != NULL)
            n->right = rotate(n->right);
        n = rotate(n);
    }
    return n;
}


template<class T>
void AVLTree<T>::levelPrint() {
    if (tree == NULL) {
        return;
    }
    queue<Node<T> *> q;
    q.push(tree);
//下一层有多少个结点需要打印
    int i = 0;
//还有多少个结点未打印
    int j = 1;
    while (!q.empty()) {
        Node<T> *p = q.front();
        q.pop();
        --j;
        printf("%d\t", p->data);
        if (p->left != NULL) {
            q.push(p->left);
            ++i;
        }
        if (p->right != NULL) {
            q.push(p->right);
            ++i;
        }
//按之字形打印
        if (j == 0) {
            printf("\n");
            j = i;
            i = 0;
        }
    }
}
