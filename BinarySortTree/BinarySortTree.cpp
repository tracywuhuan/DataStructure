#include "BinarySortTree.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T>

void BinarySortTree<T>::Inorder_real(Node<T> * &current,void (*visit)(const T &data)) {
    if (current != NULL)
    {
        Inorder_real(current->left,visit);
        visit(current->data);
        Inorder_real(current->right,visit);
    }
}
template<class T>

void BinarySortTree<T>::Insert(const T &data, Node<T> *&n) {
    if (n == NULL) {
        n = new Node<T>;
        n->left = n->right = NULL;
        n->data = data;
    }
    else if (data < n->data) {
        Insert(data, n->left);
    } else {
        Insert(data, n->right);
    }
}

template<class T>

void BinarySortTree<T>::Remove_real(const T &data, Node<T> * &b) {
    if (data == NULL) {
        cout << "invaild data!" << endl;
        return;
    }
    if (data < b->data) {
        Remove_real(data, b->left);
    } else if (data > b->data) {
        Remove_real(data, b->right);
    } else if (b->left == NULL && b->right == NULL && data != b->data) {//没找到数据
        cout << "not match any data in this tree!" << endl;
        return;
    } else if (b->left != NULL && b->right != NULL) {//非叶子节点 需要调整
        Node<T> *bb = b;     //待删除节点
        Node<T> *bbl = b->left;
        while (bbl->right)     /* 转左，然后向右走到尽头*/
        {
            bb = bbl;
            bbl = bbl->right;
        }
        b->data = bbl->data;//找到了最大值，复制到待删除的节点上
        if (bb != b)               /* 判断是否执行上述while循环 */
            bb->right = bbl->left;    /* 执行上述while循环，把移走的点的左子树接到其父节点的右子树上 */
        else
            bb->left = bbl->left;    /* 未执行上述while循环，意味着右子树没东西，直接重接左子树 */

        delete bbl;//一般是把要移走的节点的值复制到待删除节点，然后把这个删了，减少指针调整
    } else if (b->left == NULL && b->right == NULL) {  //叶子节点，直接删
        delete b;
        b = NULL;
    } else if (b->left == NULL) {//左子树为空
        Node<T> *bb = b;
        b = b->right;//右子树直接覆盖当前节点
        delete bb;
    } else {//右子树为空
        Node<T> *bb = b;
        b = b->left;//左子树直接覆盖当前节点
        delete bb;
    }
}

template<class T>
void BinarySortTree<T>::Create(const T data[], const int n)         //由数组创建二叉排序树，n是数组大小
{
    for (int i = 0; i < n; i++) {
        Insert(data[i], root);
    }
}

template<class T>
void BinarySortTree<T>::levelPrint() {
    if (root == NULL) {
        return;
    }
    queue<Node<T> *> q;
    q.push(root);
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