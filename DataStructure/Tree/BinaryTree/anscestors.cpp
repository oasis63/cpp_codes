#include<bits/stdc++.h>
using namespace std;

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

int printAncestors(Node* root,Node* node){

    if(root==NULL)
        return 0;

    if(root->right==node || root->left == node || printAncestors(root->left,node) || printAncestors(root->right,node)){

        cout<<root->value<<" ";
        return 1;
    }

    return 0;

}

//override
bool printAncestors(Node* root, int target)
{
  /* base cases */
  if (root == NULL)
     return false;

  if (root-> value == target)
     return true;

  /* If target is present in either left or right subtree of this node,
     then print this node */
  if ( printAncestors(root->left, target) || printAncestors(root->right, target) )
  {
    cout << root->value << " ";
    return true;
  }

  /* Else return false */
  return false;
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


    cout<<"\nLevel Order Traversal \n"<<endl;
    lvlT(root);

    cout<<"\nAncestors : "<<endl;

    printAncestors(root,6);


}
