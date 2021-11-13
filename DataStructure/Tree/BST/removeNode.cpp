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

int inorderSuccessor(Node* root){
    int min = root->data;
    while(root->left != NULL){
        min = root->left->data;
        root=root->left;
    }
    return min;
}


Node* removeNode(Node *root, int data){

   if(root==NULL){
    return root;
   }

   if(root->data == data){

        if(root->left == NULL && root->right == NULL)
            return NULL;
        else if(root->left == NULL && root->right != NULL){
            return root->right;
        }else if(root->left != NULL && root->right == NULL){
            return root->left;
        }else{
            int inOrdSucc = inorderSuccessor(root->right);
            root->data = inOrdSucc;
            root->right = removeNode(root->right,inOrdSucc);
        }
   }else if(data < root->data){
        root->left = removeNode(root->left,data);
   }else{
        root->right = removeNode(root->right,data);
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

    root=removeNode(root,11);

    cout<<"\nAfter Deletion of 11"<<endl;

    lvl(root);

}
