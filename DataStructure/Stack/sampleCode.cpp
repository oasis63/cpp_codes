#include<bits/stdc++.h>
using namespace std;

#define max 1000000

class Stack{
  int top;
  public:
    Stack(){
        top=-1;
    }

    int arr[max];
    int pop();
    void push(int x);
    bool isEmpty();
};

int Stack::pop(){

    if(top==-1)
        return -1;
    int temp = arr[top];
    top--;
    return temp;
}

void Stack::push(int x){
    if(top>max)
        cout<<"Stack is full"<<endl;

    top++;
    arr[top] = x;
}

bool Stack::isEmpty(){
    if(top==-1)
        return true;
    return false;
}

