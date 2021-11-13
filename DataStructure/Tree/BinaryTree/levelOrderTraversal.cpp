// tree data structure

#include<bits/stdc++.h>
using namespace std;

int imax=INT_MIN;

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


int findMax(Node* root){
    int leftMax,rightMax,max=INT_MIN;

    if(root != NULL){

        leftMax=findMax(root->left);
        rightMax=findMax(root->right);

         if(leftMax > rightMax )
            max = leftMax;
         else
            max = rightMax;

        if(max < root->value)
            max=root->value;
    }

    return max;

}

void find1(Node* root){

    if(root){

        if(root->value > imax)
            imax=root->value;
        find1(root->left);
        find1(root->right);
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

    preorder(root);

    cout<<endl;

    itrPreorder(root);

    cout<<"\nLevel Order Traversal \n"<<endl;
    lvlT(root);

    cout<<"\nMaximum Element " << findMax(root)<<endl;

    find1(root);

    cout<<imax<<endl;

}
