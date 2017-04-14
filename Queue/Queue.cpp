
#include <iostream>
#include "Queue.h"
using  namespace std;

template <class T>
Queue<T>::Queue() : frontp(-1), backp(-1){}

template <class T>
bool Queue<T>::isEmpty() const {
    return (frontp == -1 && backp == -1);
}

template <class T>
bool Queue<T>::add(const T &data) {
    if((backp+1)%MAXSIZE == frontp){
        cout<<"Queue is full!"<<endl;
        return false;
    }
    else{
        if(frontp == -1){
            frontp++;
        }
        backp = (backp+1)%MAXSIZE;
        queue[backp] = data;
        return true;
    }
}

template <class T>

bool Queue<T>::remove() {
    if(isEmpty()){
        cout<<"Queue is empty!"<<endl;
        return false;
    }
    else{
        frontp = (frontp+1)%MAXSIZE;
    }
}

template <class T>

T Queue<T>::front() const {
    if(isEmpty()){
        cout<<"Queue is empty!"<<endl;
        return NULL;
    }
    else{
        return queue[frontp];
    }
}

template <class T>

void Queue<T>::traverse(void (* visit)(const T &data)) {
    for (int i = frontp; i < backp; ++i) {
        visit(queue[i]);
    }
}

