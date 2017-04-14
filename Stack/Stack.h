#ifndef STACK_H
#define STACK_H

#define MAXSIZE 0XFFFF
template <class T>

class Stack{
private:
	T *stack;
	int top;
	int maxsize;
public:
	Stack();
	Stack(int size);
	Stack(T data[],int size);
	bool push(const T &data);
	T pop();
	T gettop();
    void traverse(void (*visit)(const T &data));
	bool isEmpty(){
		return top==-1;
	}
	bool isFull(){
		return top==maxsize-1;
	}
	bool clear(){
		top = -1;
	}
	int getsize(){
		return maxsize;
	}
	virtual ~Stack(){
		delete []stack;
	}
};
#endif