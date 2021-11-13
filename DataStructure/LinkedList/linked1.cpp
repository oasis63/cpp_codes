// Binary search tree
#include<bits/stdc++.h>
using namespace std;

// singly linked list

typedef struct node{
    int value;
    node* next;

}node;

// create node

node* newNode(int val){
    node* n;
    n=new node;
    n->value = val;
    n->next = NULL;
    return n;
}

node* insert(node* head,int val){
    if(head==NULL){
        head=newNode(val);
    }
    else{
        node* rel = newNode(val);
        rel->next = head;
        head=rel;
    }
    return head;
}

void traversal(node* head)
{

    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
}


int main(){

   node* head = NULL;
   head = insert(head,53);
   head = insert(head,143);
   head = insert(head,243);
   head = insert(head,953);

   traversal(head);

}

