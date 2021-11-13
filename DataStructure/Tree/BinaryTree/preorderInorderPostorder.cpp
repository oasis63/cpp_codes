#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, left child and right child */
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        left = NULL;
        right = NULL;
        data = x;
    }

};
 



void preorder(Node* root){
  if(root){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(Node* root){
  if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}

void postorder(Node* root){
  if(root){
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
}




// Driver program to test above functions
int main(){

    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  Node *root = new Node(10);
  root->left        = new Node(8);
  root->right       = new Node(2);
  root->left->left  = new Node(3);
  root->left->right = new Node(5);
  root->right->left = new Node(2);

  cout<<"Preorder : "<<endl;
  preorder(root);

  cout<<"\nInorder : "<<endl;
  inorder(root);

  cout<<"\nPostorder : "<<endl;
  postorder(root);

  cout<<endl;

  return 0;
}