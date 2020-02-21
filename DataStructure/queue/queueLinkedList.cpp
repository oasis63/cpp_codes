#include<bits/stdc++.h>
using namespace std;

typedef struct Qnode{
    int data;
    struct Qnode* next;
}Qnode;

typedef struct Queue{
    Qnode* front;
    Qnode* rear;
}Queue;

Qnode* newNode(int k){
    Qnode* n = new Qnode;
    n->data = k;
    n->next = NULL;
    return n;
}

Queue* newQueue(){
    Queue* q = new Queue;
    q->front=q->rear=NULL;
    return q;
}

void enQueue(Queue* q,int k){
    // create a new link list node

    Qnode* qnode = newNode(k);

    if(q->rear==NULL){
        q->front=qnode;
        q->rear=q->front;
    }

    q->rear->next = qnode;
    q->rear=q->rear->next;

}

Qnode* deQueue(Queue* q){
    if(q->front==NULL)
        return NULL;

    Qnode* temp = q->front;
    q->front = q->front->next;

    if(q->front==NULL)
        q->rear=NULL;

    return temp;
}

void printQ(Queue* q){
    if(q->rear==NULL){
        cout<<"Empty Queue"<<endl;
        return ;
    }

    Qnode* temp = q->front;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;

}

int main(){
    Queue *q = newQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);

    printQ(q);

    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    Qnode *n = deQueue(q);
    if (n != NULL)
      printf("Dequeued item is %d", n->data);
    return 0;

}


