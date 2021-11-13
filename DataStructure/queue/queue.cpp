#include<bits/stdc++.h>
using namespace std;

class Queue{
int rear,front,capacity,size;
int *arr;

public:

    Queue(int cap){
        capacity = cap;
        rear=capacity-1;
        front=size=0;
        arr = new int[sizeof(int)*capacity];
    }

    void push(int t);
    int pop();
    int isEmpty();
    int isFull();
    void print();
};

void Queue::print(){
    if(front > rear){
        for(int i=0;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=front;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
    }

}

int Queue::isFull(){
    if(size==capacity)
        return 1;
    return 0;
}

int Queue::isEmpty(){
    if(size==0)
        return 1;
    return 0;
}

int Queue::pop(){
    if(!isEmpty()){
        int item = arr[front];
        front = (front+1)%capacity;
        size--;
        return item;
    }
    else
        //cout<<"Empty Stack "<<endl;
        return INT_MIN;
}

void Queue::push(int t){
    if(!isFull()){
        rear = (rear+1)%capacity;
        arr[rear] = t;
        size++;
    }
    else
        cout<<"Queue is Full"<<endl;
}

int main(){
    int s;cin>>s;
    Queue Q(s);

    Q.push(5);
    Q.push(3);
    Q.push(0);
    Q.push(10);

    Q.print();

    cout<<endl;

    cout<<Q.pop()<<endl;

}
