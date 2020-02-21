#include<bits/stdc++.h>
using namespace std;

// Generic Trees -----  N-ary Trees

typedef struct Node{
    int data;
    Node* firstChild;
    Node* nextSibling;

}Node;

// Number of sibling in the

Node* newNode(int value){
    Node* n = new Node();
    n->data = value;
    n->firstChild=NULL;
    n->nextSibling=NULL;
    return n;
}



int countSiblings(Node* root){
    int count=0;

    while(root){
        count++;
        root = root->nextSibling;
    }
    return count;
}

int countChild(Node* root){
    int count=0;

    root=root->firstChild;

    while(root){
        count++;
        root = root->nextSibling;
    }
    return count;
}

// sum of all the nodes in the N-ary Tree

int sumNodes(Node* root){
    if(root==NULL)
        return 0;
    return(root->data + sumNodes(root->firstChild) + sumNodes(root->nextSibling));
}

int main(){

    Node* root=newNode(1);
    root->firstChild=newNode(2);
    root->firstChild->nextSibling=newNode(3);
    root->firstChild->firstChild=newNode(4);
    root->firstChild->firstChild->nextSibling=newNode(5);
    root->firstChild->firstChild->nextSibling->firstChild=newNode(7);
    root->firstChild->nextSibling->firstChild=newNode(6);
    root->firstChild->nextSibling->firstChild->nextSibling=newNode(8);
    root->firstChild->nextSibling->firstChild->nextSibling->nextSibling=newNode(9);

    cout<<"Number of Children of root : "<<countChild(root)<<endl;

    cout<<"Number of siblings of root->firstChild :" <<countSiblings(root->firstChild)<<endl;

    cout<<"Number of Children of  root->firstChild->nextSibling: "<<countChild(root->firstChild->nextSibling)<<endl;

    cout<<"\nSum of all the nodes : " <<sumNodes(root)<<endl;

}












