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
        return -1;
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

void preorderS(Node* root){  // DLR  using Stack
    stack<Node*>s;

    if(!root)
        return;

    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();s.pop();
        cout<<temp->data<<" ";

        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }

}


// Levelling each node in the tree

void levelNodes(Node* root){

    int level[10];
    queue<Node*>q;

    q.push(root);

    for(int i=0;i<10;i++){
        level[i]=-1;
    }

    level[root->data]=0;

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->left){
            q.push(temp->left);
            level[temp->left->data] = level[temp->data]+1;
        }
        if(temp->right){
            q.push(temp->right);
            level[temp->right->data] = level[temp->data]+1;
        }
    }



    for(int i=0;i<10;i++){
        if(level[i]!=-1)
            cout<<level[i]<<" ";
    }

    cout<<endl;


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

    root=insert(root,6);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,7);

    cout<<"Preorder"<<endl;
    preorderS(root);
    cout<<endl;

    cout<<height(root)<<endl;

    cout<<"Levels of each Node"<<endl;
    levelNodes(root);
}
