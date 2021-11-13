#include<bits/stdc++.h>
using namespace std;


/*
Steps to delete a node

1) find the node that is to be deleted
2) find the deepest node
3) replace the deepest node's data with the node to be deleted
4) delete the deepest node

*/




int imax=INT_MIN;


class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};

Node* newNode(int v){
    Node* node = new Node(v);
    return node;
}

void preorder(Node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* find(Node* root,int elem){
    if(root==NULL)
        return NULL;
    else if(root->value == elem)
        return root;
    else{
        Node* rL = find(root->left,elem);

        if(rL)
            return rL;
        else
            return(find(root->right,elem));
    }
}


Node* deepestNode(Node* root){
    if(root==NULL)
        return NULL;

    queue<Node*>q;
    q.push(root);

    Node* temp;

    while(!q.empty()){
        temp = q.front(); q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return temp;
}


int deleteNode(Node* root,int elem){

    Node* delNode = find(root,elem);

    if(delNode==NULL)
        return 0;

    Node* deepNode = deepestNode(root);

    delNode->value = deepNode->value;

    // deleting the deepest node

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->left == deepNode){
            delete temp->left;
            temp->left = NULL;
            break ;
        }
        else if( temp->right == deepNode){
            delete temp->right;
            temp->right = NULL;
            break;
        }

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }

    return 1;

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

    cout<<"Before Deletion "<<endl;
    preorder(root);

    int value = deleteNode(root,15);

    cout<<"\nDelete Status : "<<value<<endl;

    cout<<"After Deletion "<<endl;
    preorder(root);

    cout<<endl;

    value = deleteNode(root,1);

    cout<<"\nDelete Status : "<<value<<endl;


    cout<<"After Deletion "<<endl;
    preorder(root);

}
