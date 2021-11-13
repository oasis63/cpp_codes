//reversing a linked list using stack

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* next;

}Node;


Node* newNode(int data){
    Node* n = new Node;
    n->data = data;
    n->next = NULL;
    return n;
}

void print(Node* head){
    if(head==NULL)
        return;

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

// insert the element at the start

Node* insert(Node* head,int data){
    if(head==NULL)
        return newNode(data);

    Node* n = newNode(data);

    Node* temp = head;
    head=n;
    head->next=temp;

    return head;
}

Node* insertEnd(Node* head,int data){
    if(head==NULL)
        return newNode(data);

    Node* n = newNode(data);
    Node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
    return head;
}

// reversing a Linked List using stack

Node* reverseLinkedList(Node* head){
    if(head==NULL)
        return head;

    stack<Node*> s;

    Node* temp = head;

    while(temp!=NULL){
        s.push(temp);
        temp=temp->next;
    }

    temp=s.top(); s.pop();
    head=temp;

    while(!s.empty()){
        temp->next = s.top(); s.pop();
        temp=temp->next;
    }
    temp->next=NULL;

    return head;

}

int main(){

    Node* head=NULL;

    for(int i=1;i<=4;i++)
        head=insertEnd(head,i);
    print(head);

    cout<<"\nLinked List after reversal "<<endl;

    head = reverseLinkedList(head);
    print(head);
}

