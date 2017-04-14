#include "Stack.h"
#include <iostream>

using namespace std;
template<class T>
Stack<T>::Stack():top(-1),maxsize(MAXSIZE){
	stack=new T[maxsize];
	if(stack==NULL){
		cout<<"new address space failed!"<<endl;
		exit(1);
	}
}

template<class T>
Stack<T>::Stack(int size):top(-1),maxsize(size){
	stack=new T[maxsize];
	if(stack==NULL){
		cout<<"new address space failed!"<<endl;
		exit(1);
	}
}

template<class T>
Stack<T>::Stack(T data[],int size):top(-1),maxsize(size){
	stack=new T[maxsize];
	if(stack==NULL){
		cout<<"new address space failed!"<<endl;
		exit(1);
	}
	for (int i = 0; i < maxsize; ++i)
	{
		stack[i]=data[i];
	}
	top = top + maxsize;
}

template<class T>
bool Stack<T>::push(const T &data){
    if(isFull()){
        cout<<"push failed: out of capacity!"<<endl;
        return false;
    }
    stack[++top] = data;
}

template<class T>
T Stack<T>::pop(){
    if(isEmpty()){
        cout<<"pop failed: stack is empty!"<<endl;
        return false;
    }
    return stack[top--];
}

template<class T>
T Stack<T>::gettop(){
    if(isEmpty()){
        cout<<"gettop failed: stack is empty!"<<endl;
        return false;
    }
    return stack[top];
}

template <class T>

void Stack<T>::traverse(void (*visit)(const T &data)) {
    for (int i = 0; i < top; ++i) {
        visit(stack[i]);
    }
}
