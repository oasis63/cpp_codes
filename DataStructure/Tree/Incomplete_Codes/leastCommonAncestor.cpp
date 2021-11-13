// binary search tree

#include<bits/stdc++.h>
using namespace std;

// in structure all the public access is by default
class Node
{

public:

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


Node* ans = NULL;

Node* newNode(int val){
    Node* n;   // pointer to the class
    n=new Node(val);   // memory block of the class
    return n;
}

Node* insert(Node* root,int val){
    if(root==NULL){
        root=newNode(val);
    }
    else if( val > root->data){
        root->right = insert(root->right,val);
    }
    else if(val < root->data){
        root->left = insert(root->left,val);
    }
    return root;
}

void inorder(Node* root){   // LDR
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}




int find(Node* root,int elem){

    if(root==NULL)
        return 0;
    else if( root->data == elem)
        return 1;
    else{


        int rL = find(root->left,elem);
        if(rL)
              return rL;
        else
            return(find(root->right,elem));

    }

}

int find2(Node* root,int elem){

    if(root==NULL)
         return 0;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->data == elem)
            return 1;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }


    return 0;

}




Node *lca(Node *root, int v1,int v2)
{
  if(root==NULL)
      return NULL;
   else{
       // cosidering root to be the answer

       int v1s,v2s;

       if(v1 > root->data && v2 < root->data){
           v1s = find2(root->right,v1);
           v2s= find2(root->left,v2);

       }
       else if( v1 < root->data && v2 > root->data) {
           v1s = find2(root->left,v1);
           v2s = find2(root->right,v2);
       }
       else if( v1 < root->data && v2 < root->data ){
           v1s = find2(root->left,v1);
           v2s = find2(root->left,v2);
       }
       else if( v1 > root->data && v2 > root->data ){
           v1s = find2(root->right,v1);
           v2s = find2(root->right,v1);
       }

        if(v1s && v2s )
            ans = root;

        // if not

        Node* rL = lca(root->left,v1,v2);

        if(rL)
            return rL;
        else
            return lca(root->right,v1,v2);

   }


}




int main(){
    Node* root = NULL;

    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,9);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,5);


    //cout<<root->data<<endl;

    cout<<"Inorder"<<endl;
    //inorder(root);

    cout<<lca(root,1,2)<<endl;

    cout<<ans->data<<endl;


}






