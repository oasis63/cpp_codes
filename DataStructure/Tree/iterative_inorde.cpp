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
    return n;
}

void inorder(Node* root){
    if(root){
        //LDR
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// complete code for iterative inorder
void iterative_inorder(Node* root){
    stack<Node*> st;

    while(1){
        while(root){
            st.push(root);
            root=root->left;
        }

        if(st.empty())
            break;
        root=st.top();  st.pop();

        cout<<root->data<<" ";
        root=root->right;
    }

}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->right = newNode(7);
    root->right->left = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"\n\nRecursive Inorder "<<endl;
    inorder(root);

    cout<<"\n\nIterative Inorder"<<endl;
    iterative_inorder(root);
}






