#include <bits/stdc++.h>
using namespace std;

#define li long int
#define max 10000


// First In Last Out


class Stack{
    int top;
public:
    Stack(){
        top=-1;
    }

    int arr[max];  // maximum size of the stack

    bool push(int x);
    int pop();
    bool isEmpty();
    void reverseStack();
    void print();
};

void Stack::print(){
    while(!isEmpty()){
        int x = pop();
        cout<<x<<" ";
    }
}

bool Stack::push(int x){
    if(top > max){
        cout<<"Stack overflow"<<endl;
        return false;
    }
    else{
        top++;
        arr[top]=x;
        return true;
    }
}

int Stack::pop(){
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
        return -1;
    }

    int x =arr[top];
    top--;
    return x;
}

bool Stack::isEmpty(){
    if(top==-1)
        return true;
    return false;
}


void Stack::reverseStack(){
    if(isEmpty())
        return;
    int t = pop();
    reverseStack();
    cout<<t<<" ";
    //push(t);
}


// driver class



int main(){
    Stack s;
    s.push(234);
    s.push(134);
    s.push(234);
    cout<<"Element Pushed :" <<s.push(304)<<endl;

   // s.print();

    s.reverseStack();

    //s.print();

    //cout<<s.pop()<<endl;
   // cout<<s.pop()<<endl;

}
