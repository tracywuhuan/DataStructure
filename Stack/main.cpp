#include "Stack.cpp"

template <class T>
void visit(T data){
    cout<<data<<"-";
}
int main()
{
    int data[10]={1,2,3,4,5,6,7,8,9,10};

    Stack<int> stack(data,10);

    stack.traverse(visit);
    cout<<stack.gettop();
    while(!stack.isEmpty()){
        cout<<stack.pop()<<" ";
    }

    cout<<endl;

    return 0;
}