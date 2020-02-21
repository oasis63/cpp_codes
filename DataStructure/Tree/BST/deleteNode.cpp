//delete node from a tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;


Node* newNode(int value){
    Node* n = new Node();
    n->data =value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root,int data){
    if(root==NULL)
        root=newNode(data);
    else if( data > root->data)
        root->right = insert(root->right,data);
    else if( data < root->data)
        root->left = insert(root->left,data);
    return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void lvl(Node* root ){

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }


}

// find max in bst

Node* findMax(Node* root){

    if(root==NULL)
        return root;
    else if(root->right==NULL)
        return root;
    else
        return findMax(root->right);
}


Node* find(Node* root,int data){
    if(!root)
        return NULL;
    else if(root->data > data)
        return find(root->left,data);
    else if(root->data < data)
        return find(root->right,data);
    return root;
}


Node* deleteNode(Node* root , int data){

   if(root==NULL){
    cout<<"Element is not present"<<endl;
    return root;
   }

    Node* mxLeftNode = findMax(root->left);
    Node* findNode  = find(root,data);

    findNode->data = mxLeftNode->data;

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp -> right == mxLeftNode ){
            delete temp->right;
            temp->right = NULL;
            cout<<"\n" <<data <<" Deleted Successfully"<<endl;
            return root;
        }
        else  if(temp -> left == mxLeftNode ){
            delete temp->left;
            temp->left = NULL;
            cout<<"\n" <<data <<" Deleted Successfully"<<endl;
            return root;
        }

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return root;

}



int main(){
    Node* root=NULL;

    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,0);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,11);

    lvl(root);

    cout<<endl;

    root=deleteNode(root,11);

    cout<<"\nAfter Deletion "<<endl;

    lvl(root);

}
