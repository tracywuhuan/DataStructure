#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>

template<class T>

struct Node{
	T data;
	Node<T> *next;
};

template<class T>
class LinkList{
private:
	Node<T> *head;
	Node<T> *current;
	inline void deepCopy(const LinkList<T> &original);   //"深复制"  
public:
	LinkList();
    LinkList(const LinkList<T> &aplist);  
    ~LinkList();  
    LinkList<T>& operator=(const LinkList<T> &rlist);  
    void insert_head(const T &element);  //在链表的头部之前插入  
    void insert_end(const T &element);  //在链表的尾部插入  
    bool first(T &listEl);     //得到第一个的数据  
    inline bool getNext(T &listEl);   //得到当前指针所指的下一个数据  
    bool find(const T &element);    //查找一个数据  
    bool retrieve(T &element);       //检索一个数据  
    bool replace(const T &newElement);    //更改一个数据  
    bool remove(T &element);  
    bool isEmpty() const;  
    void Empty();  
};
#endif