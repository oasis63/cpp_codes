#include <bits/stdc++.h>
using namespace std;

void enqueue(int queue[], int element, int& rear, int arraySize,int &count) {
    if(rear == arraySize)            // Queue is full
        printf("OverFlow\n");
    else {
        queue[rear] = element;    // Add the element to the back
        rear++;
        count++;
    }
}


int dequeue(int queue[], int& front, int rear,int& count) {
    int ret=-1;
    if(front == rear){            // Queue is empty
        //printf("UnderFlow\n");
        return ret;
    }
    else {
        ret = queue[front];
        queue[front] = 0;        // Delete the front element
        front++;
        count--;
    }
    return ret;
}

int Front(int queue[], int front) {
    return queue[front];
}


int main() {

    int queue[100];
    int front = 0, rear = 0;
    int arraySize = 100;                // Size of the array
    int count=0;

    int q;cin>>q;
    while(q--){
        char ch;cin>>ch;
        if(ch=='E'){
            int elem;cin>>elem;
            enqueue(queue,elem,rear,arraySize,count);
            cout<<count<<endl;
        }else{
            int ret = dequeue(queue,front,rear,count);
            cout<<ret<<" "<<count<<endl;
        }
    }

}

