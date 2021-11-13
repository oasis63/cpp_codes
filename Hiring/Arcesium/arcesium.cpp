#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int v){
        val = v;
        next = NULL;
    }
};

Node* rev(Node* head){

    Node*prev = NULL;
    Node*n = NULL;

    while(head!=NULL){
        n = head;
        head = head->next;
        n->next = prev;
        prev = n;
    }
    return n;
}

void print(Node* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insert(Node* head,int v){

    if(head == nullptr){
        head = new Node(v);
    }else{
        Node * newNode = new Node(v);
        newNode->next = head;
        head=newNode;
    }
    return head;
}

int main(){

    Node* head = nullptr;

    for(int i=0;i<5;i++){
        head = insert(head,i);
    }

    print(head);
    Node* r = rev(head);
    print(r);

    // reverse a string


    string str = "hello";
    reverse(str.begin(),str.end());
    cout<<str<<endl;

    return 0;
}
