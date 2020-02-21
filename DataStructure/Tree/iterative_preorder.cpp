//Binary Tree traversal without recursion

#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* newNode(int data){
    Node* n = new Node;
    n->data = data;
    n->left=n->right=NULL;
}


void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// recursive PreOrder Traversal DLR

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Iterative Preorder Traversal
// have to follow DLR

void iterativePreorder(Node* root){
    stack<Node*>NodeStack;
    NodeStack.push(root);

    while(!NodeStack.empty()){  // stack is not empty

        Node* root = NodeStack.top();
        cout<<root->data<<" ";
        NodeStack.pop();

        // storing the right an left children of the the popped nodes
        // Data - > Left - > Right

        if(root->right)
            NodeStack.push(root->right);
        if(root->left)
            NodeStack.push(root->left);
    }
}



int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    iterativePreorder(root);

}


