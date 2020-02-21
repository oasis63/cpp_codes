#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left=NULL;
        right=NULL;
    }
};

Node* newNode(int v){
    Node* node = new Node(v);
    return node;
}

// DLR

void preorder(Node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}



// element insertion in binary tree  using level order traversal

void insert(Node* root,int value){
    queue<Node*> q;

    if(root==NULL){
        root=newNode(value);
        return;
    }

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->left)
            q.push(temp->left);
        else{   // if the left child is null we can insert here
                temp->left = newNode(value);
                return;
        }

        if(temp->right)
            q.push(temp->right);
        else{  // if right child is null
            temp->right = newNode(value);
            return;
        }
    }
}

int height(Node* root){
    if(root==NULL)
        return 0;
    else{

        int lheight = height(root->left);
        int rheight = height(root->right);

        if(lheight > rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}


// level order traversal

void lvlT(Node* root){

    if(root==NULL)
        return;

    queue<Node*>q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        cout<<temp->value<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

Node* mirror(Node* root){


    if(root){
        mirror(root->left);
        mirror(root->right);

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

    }

    return root;
}


int main(){
    Node* root=NULL;

    root=newNode(3);
    root->left= newNode(1);
    root->right = newNode(5);
    root->left->left=newNode(10);
    root->left->right=newNode(2);
    root->right->left=newNode(4);
    root->right->right=newNode(6);
    root->right->right->left=newNode(9);
    root->right->right->right=newNode(10);
    //root->right->right->right->right=newNode(11);


    lvlT(root);

    cout<<"\n------Mirror Image Tree----"<<endl;

    root = mirror(root);

    lvlT(root);

}
