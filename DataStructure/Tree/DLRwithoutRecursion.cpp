// binary search tree

// incomplete ... with  wrong answer

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

class Stack{
int top;
int capacity;
Node** arr;     // pointer to pointer
public:
    Stack(int cap){
        top=-1;
        capacity=cap;
        arr = new Node*[capacity];   // array of Node* pointer
    }

    void push(Node* t);
    Node* pop();
    int isEmpty();
};

int Stack::isEmpty(){
    if(top==-1)
        return 1;
    return 0;
}

Node* Stack::pop(){
    if(!isEmpty()){
        Node* item = arr[top];
        top--;
        return(item);
    }
}

void Stack::push(Node* t){
    top++;
    arr[top]=t;
}

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
    return root;
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
    Stack S(50);
    while(1){
        while(root){
            cout<<root->data<<" ";
            S.push(root);
            root=root->left;
        }
        if(S.isEmpty())
            break;
        Node* root = S.pop();
        root = root->right;
    }

}

int main(){
    Node* root = NULL;

    root=insert(root,4);
    root=insert(root,9);
    root=insert(root,0);
    root=insert(root,-3);
    root=insert(root,10);

    cout<<"----Inorder----"<<endl;
    inorder(root);

    cout<<"\n---PreOrder---"<<endl;
    preorderS(root);

    cout<<"\nRoot node is : "<<root->data<<endl;

    cout<<"\nHeight of the Tree is : ";

    cout<<height(root)<<endl;
}
