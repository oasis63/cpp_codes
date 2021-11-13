#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node *root)
{
    stack<node*>st;
    st.push(root);

    while(!st.empty()){
        node* node = st.top();
        cout<<node->data<<" ";
        st.pop();

        if(node->right)
            st.push(node->right);
        if(node->left)
            st.push(node->left);

    }
}

// iterative inorder LDR

void iterativeInorder(node* root){
    stack<node*> st;

    while(1){
        while(root){
            st.push(root);
            root=root->left;
        }

        if(st.empty())
            break;
        root=st.top();  st.pop();

        cout<<root->data<<" ";
        root=root->right;
    }

}
//LDR
void inorder(node* root){
    if(root){
        inorder(root->left);   // L
        cout<<root->data<<" ";  // D
        inorder(root->right); // R
    }
}

// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);

  cout<<"\n----Iterative Preorder Traversal-----"<<endl;
  iterativePreorder(root);

  cout<<"\n\n---Inorder Traversal --- \n"<<endl;

  inorder(root);

  cout<<"\n\n-----Iterative Inorder--\n\n";
  iterativeInorder(root);

  cout<<endl;
  return 0;
}
