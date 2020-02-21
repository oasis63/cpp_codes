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

Node* findMin(Node* root){

    if(root==NULL)
        return root;
    else if(root->left==NULL)
        return root;
    else
        return findMax(root->left);
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




struct node* deleteNode2(struct node* root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode2(root->left, key);

    else if (key > root->data)
        root->right = deleteNode2(root->right, key);

    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode2(root->right, temp->data);
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

    root=deleteNode2(root,5);

    cout<<"\nAfter Deletion "<<endl;

    lvl(root);

}
