/* stack data structure
LIFo - last in First out */

#include<iostream>
using namespace std;

class Stack{

// Data of the ADT (Abstract Data Type)
int top;
int capacity;
int *arr;

// Methods of the ADT
public:
    Stack(int size){
        capacity = size;
        top=-1;
        arr = new int[sizeof(int)*capacity];
    }

    void push(int t);
    void pop();
    int isEmpty();
    int isFull();
    int topElem();
    void deleteStack();
    int size();
    void print();
    int getCapacity();
};

int Stack::getCapacity(){
    return capacity;
}

void Stack::print(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int Stack::size(){
    return top+1;
}

void Stack::deleteStack(){
    if(arr){
        delete[] arr;
    }
}

int Stack::topElem(){
    if(!isEmpty()){
        return arr[top];
    }
}

int Stack::isFull(){
    if(top==capacity-1)
        return 1;
    return 0;
}

int Stack::isEmpty(){
    if(top==-1)
        return 1;
    return 0;
}

void Stack::pop(){
    if(!isEmpty()){
        top--;
    }
    else
        cout<<"Empty Stack "<<endl;
}

void Stack::push(int t){
    if(!isFull()){
        top++;
        arr[top]=t;
    }
    else
        cout<<"Stack is Full"<<endl;
}

int main(){
    int size;cin>>size;
    Stack t(size);

    t.push(34);
    t.push(2);
    t.push(3);

    cout<<"Elements in the stack ";
    t.print();

    cout<<"\nTop Element "<<t.topElem()<<endl;
    cout<<"\nsize of the stack : "<<t.size()<<endl;
    cout<<"\nCapacity of the stack : "<<t.getCapacity()<<endl;

    t.pop();
    t.pop();

    cout<<"\n\nAfter 2 pop() operations,stack is ";
    t.print();
}
