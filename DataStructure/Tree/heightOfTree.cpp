#include <bits/stdc++.h>
using namespace std;
/*
    Height of a node is the length of the path from that node to
    the deepest node.

    Height of a tree is the length of the path from root to the
    deepest node.

    Height of leaf nodes is 0 .

    Depth of a node is the length of the path from that node to the
    root.

    Depth of deepest node == Height of the tree


*/


class node{
public:
    int value;
    node* left;
    node* right;

    node(){
        left=NULL;
        right=NULL;
    }

    node(int v){
        value=v;
        left=NULL;
        right=NULL;
    }

};

node* newNode(int val){
    node* n = new node(val);
    return n;
}


void preorder(node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}



int height(node* root){
    if(root==NULL)  // height of a empty tree is -1
        return -1;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);

        if(rheight > lheight){
            return (rheight+1);
        }
        else{
            return (lheight+1);
        }
    }
}

int main()
{
    node* root= newNode(1);
    root->left= newNode(2);
    root->left->left= newNode(4);
    root->left->right= newNode(5);
    root->left->right->left= newNode(8);
    root->left->right->right= newNode(9);
    root->right= newNode(3);
    root->right->right= newNode(7);
    root->right->left= newNode(6);


    cout<<"\nHeight Of the Tree is "<< height(root)<<endl;



    return 0;
}
