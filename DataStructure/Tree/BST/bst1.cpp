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

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}


Node* insert(Node*& root, int val){
    if(root==NULL)
        return newNode(val);
    else if( val < root->value)
        root->left = insert(root->left, val);
    else if(val > root->value)
        root->right = insert(root->right , val);
    return root;
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

int printAncestors(Node* root,int target){
    if(root==NULL)
        return 0;

    if(root->value == target)
        return 1;

    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        cout<<root->value<<" ";
        return 1;
    }
    return 0;
} 

// finding the least common ancestor LCA

Node* LCA(Node* root, Node* a, Node*b){

    while(1){

        if((a->value < root->value && b->value > root->value ) || (a->value > root->value && b->value < root->value))
            return root;

        if(a->value > root->value)
            root=root->right;
        else
            root = root->left;
    }

}

Node* LCA(Node* root, int a, int b){

    while(1){

        if((a < root->value && b > root->value ) || (a > root->value && b < root->value))
            return root;

        if(a > root->value)
            root=root->right;
        else
            root = root->left;
    }

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

    inorder(root);


    cout<<endl;


    cout<<"\nLevel Order Traversal \n"<<endl;
    lvlT(root);

    cout<<"\nAncestors : "<<endl;

    printAncestors(root,6);

    cout<<"\nLeast Common Ancestor ofo 5 and 1 is "<<endl;

    cout<<LCA(root,5,1)->value<<endl;

}
