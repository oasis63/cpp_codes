//delete node from a tree 

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
    Node* n = new Node(v);
    return n;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}

// printing the tree in level order traversal

void levelOrder(Node* root){

    if(root==NULL)
        return;

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();
        cout<<temp->value<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }
    cout<<endl;
}


int height(Node *root){
    if(!root)
        return -1;
    else{
        int r_ht = height(root->right);
        int l_ht = height(root->left);

        return 1+max(r_ht,l_ht);
    }
}

// dimeter 

int diameter(Node* root){

    int rHeight = height(root->right);
    int lHeight = height(root->left);

    cout<<"rHeight : "<<rHeight<<endl;
    cout<<"lHeight : "<<lHeight<<endl;

    int dmtr =  rHeight + lHeight + 2;

    return dmtr;
}

int main(){

    Node* root = newNode(1);
    root->left = newNode(2);
    root->left->right = newNode(5);
    root->left->left = newNode(4);
    root->right = newNode(3);

    levelOrder(root);
    cout<<endl;
    inorder(root);

    cout<<"Height : "<<height(root)<<endl;

    cout<<"\nDiameter : " << diameter(root)<<endl;

}


