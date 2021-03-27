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

void preorder(Node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
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

    Node* temp;

    while(!q.empty()){
        Node* temp = q.front(); q.pop();
        cout<<temp->value<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

}



Node* preToBSTUtil(vector<int> preorder,int &preIndex,int low,int high,int n){

    if(preIndex > n || low > high)
        return NULL;

    Node* root = new Node(preorder[preIndex]);
    preIndex++;

    if(low == high)
        return root;

    int i=0;
    for(i=low;i<=high;i++){
        if(preorder[i] > root->value)
            break;
    }


    root->left = preToBSTUtil(preorder,preIndex,preIndex,i-1,n);

    root->right = preToBSTUtil(preorder,preIndex,i,high,n);

    return root;
}



Node* preToBSt(vector<int> preorder){
    int preIndex = 0;
    int n = preorder.size();
    return preToBSTUtil(preorder,preIndex,0,n-1,n);
}





int main(){

 /*   Node* root=NULL;

    root=insert(root,8);
    root=insert(root,5);
    root=insert(root,1);
    root=insert(root,7);
    root=insert(root,10);
    root=insert(root,12);

    inorder(root);

    cout<<"\nLevel Order Traversal \n"<<endl;
    lvlT2(root);

    cout<<endl;*/

    // preorder(root);

    vector<int> preorder{8,5,1,7,10,12};

    Node* ans = preToBSt(preorder);


    lvlT(ans);


    return 0;
}
