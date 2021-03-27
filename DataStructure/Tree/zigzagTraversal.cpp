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

// DLR
void preorder(node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// LDR
void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}

// level order traversal 

void lvl(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();q.pop();
        cout<<temp->value<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}


// zigzag traversal

void levelElem(node* root,int level,vector<vector<int>> &result){
    if(!root)
        return;
    result[level].push_back(root->value);
    levelElem(root->left,level+1,result);
    levelElem(root->right,level+1,result);
}

void zigzag(node* root){
    vector<vector<int>> result;
    levelElem(root,0,result);
    cout<<"Size of the result vector : "<< result.size()<<endl;
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
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


    // cout<<"\nHeight Of the Tree is "<< height(root)<<endl;

    // inorder(root);

    // cout<<"\npreorder"<<endl;

    // preorder(root);

    // cout<<"\nLevel order traversal"<<endl;

    // lvl(root);

    cout<<"\nZigzag Traversal"<<endl;

    zigzag(root);




    return 0;
}
