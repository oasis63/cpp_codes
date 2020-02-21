//a very simple binary tree 0 , 1 ,2
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;

}Node;

Node* newNode(int data){
    Node* n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
};

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    Node* root=NULL;
    root=newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right=newNode(3);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    preorder(root);

}
