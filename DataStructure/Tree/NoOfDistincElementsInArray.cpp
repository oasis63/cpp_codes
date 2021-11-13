/*

Distinct Count ||

Distinct Elements in an array 

*/

#include <iostream>
using namespace std;

int elemCount=0;

class Node{
 public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left=right=NULL;
    }
};

Node* newNode(int v){
    Node* n  = new Node(v);
    return n;
}

Node* insert(Node* root,int v){
    if(root==NULL)
        root=newNode(v);
    else if( v > root->data)
        root->right = insert(root->right ,v);
    else if( v < root->data)
        root->left = insert(root->left,v);
    return root;
}

void preorder(Node* root){ // DLR
    if(root){
        elemCount++;
        preorder(root->left);
        preorder(root->right);
    }
}


int main()
{
   int cases;cin>>cases;
   while(cases--){
       int n,x;cin>>n>>x;
    
        Node* root = NULL;
     
       for(int i=0;i<n;i++){
            int temp;cin>>temp;
            root=insert(root,temp);
       }
       
       preorder(root);
       
       if(elemCount == x)
        cout<<"Good"<<endl;
       else if( elemCount < x)
        cout<<"Bad"<<endl;
        else
            cout<<"Average"<<endl;
       elemCount=0;
   }
}
