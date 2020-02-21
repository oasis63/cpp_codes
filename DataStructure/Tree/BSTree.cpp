// binary search tree

#include<bits/stdc++.h>
using namespace std;

// in structure all the public access is by default

class Node
{

public:

    int data;
    Node* left;
    Node* right;

    Node(){
        left=NULL;
        right=NULL;
    }

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* newNode(int val){
    Node* n;   // pointer to the class
    n=new Node(val);   // memory block of the class
    return n;
}

Node* insert(Node* root,int val){
    if(root==NULL){
        root=newNode(val);
    }
    else if( val > root->data){
        root->right = insert(root->right,val);
    }
    else if(val < root->data){
        root->left = insert(root->left,val);
    }
    //return root;
}

void inorder(Node* root){   // LDR
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// preorder  DLR

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// height of the tree
int height(Node* root ){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);

        if(lheight > rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}

void preorderS(Node* root){
    stack<Node*>S;

    while(1){
        while(root){
            cout<<root->data<<" ";
            S.push(root);
     //       S.show();
            cout<<endl;
            root=root->left;
        }
        if(S.empty())
            break;
        Node* root = S.top();
        S.pop();
        root = root->right;
    }

}

Node* find(Node* root,int data){

    if(!root)
        return NULL;

    if(root->data > data)
        return find(root->left,data);
    else if(root->data < data)
        return find(root->right,data);

    return root;

}

int main(){
    Node* root = NULL;

    root=insert(root,4);
    root=insert(root,9);
    root=insert(root,0);
    root=insert(root,-3);
    root=insert(root,10);

    cout<<"Inorder"<<endl;
    inorder(root);

    cout<<"PreOrder"<<endl;
    preorderS(root);

    cout<<"\nRoot node is : "<<root->data<<endl;

    cout<<"\nHeight of the Tree is : ";

    cout<<height(root)<<endl;
}
