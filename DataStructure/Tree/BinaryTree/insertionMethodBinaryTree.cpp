// tree data structure

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

// preorder without recursion

void itrPreorder(Node* root){
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();  s.pop();

        cout<<temp->value<<" ";

        if(temp->right)
            s.push(temp->right);
        if(temp->right)
            s.push(temp->left);
    }
}

// level order traversal

void lvlT(Node* root){

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




int main(){
    Node* root=NULL;

    root=newNode(3);
    root->left= newNode(1);
    root->right = newNode(5);
    root->left->left=newNode(0);
    root->left->right=newNode(2);
    root->right->left=newNode(4);
    root->right->right=newNode(6);

    cout<<"PreOrder before insertion "<<endl;

    preorder(root);

    cout<<endl;

    cout<<"\nHow many Elements to be inserted "<<endl;
    int n;cin>>n;

    while(n--){
        int temp;cin>>temp;
        insert(root,temp);
    }

    cout<<"Elements after insertion "<<endl;

    itrPreorder(root);

    cout<<"\nLevel Order Traversal \n"<<endl;
    lvlT(root);

}
