#include <iostream>
#include "Queue.cpp"
template <class T>

void visit(T data){
    cout<<data<<"-";
}
int main() {
    Queue<int> *queue = new Queue<int>();
    for (int i = 0; i < 10; ++i) {
        queue->add(i);
    }
    queue->traverse(visit);
    return 0;
}