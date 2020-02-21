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

void itrPreorder(Node* root){
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top(); s.pop();
        cout<<temp->value<<" ";

        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);

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

int findMax(Node* root){
    int leftMax,rightMax,max=INT_MIN;

    if(root != NULL){

        leftMax=findMax(root->left);
        rightMax=findMax(root->right);

         if(leftMax > rightMax )
            max = leftMax;
         else
            max = rightMax;

        if(max < root->value)
            max=root->value;
    }

    return max;

}

void findMax1(Node* root){    // Inorder

    if(root){

        if(root->value > imax)
            imax=root->value;
        findMax1(root->left);
        findMax1(root->right);
    }
}

// non-recursively finding the maximum element
// level order traversal to find the max

int maxElem(Node* root){
    queue<Node*> q;
    q.push(root);

    int max = INT_MIN;


    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->value > max)
            max=temp->value;

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);

    }

    return max;

}

int search(Node* root,int elem){
    if(root==NULL)
        return 0;
    else if(root->value == elem)
        return 1;
    else{

       int l = search(root->left,elem);

       if(l==1)
        return 1;
       else
        return(search(root->right,elem));
    }

    return 0;
}

// using level order traversal to find an element

int find(Node* root,int elem){

    queue<Node*>q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();
        if(temp->value == elem)
            return 1;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return 0;

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

    itrPreorder(root);

    cout<<"\nLevel Order Traversal \n"<<endl;
    lvlT(root);

    cout<<"\nMaximum Element \n"<<endl;

    cout<<findMax(root)<<endl;

    cout<<"Iterative Maximum Element " <<maxElem(root)<<endl;


    int te=3;

   while(te--){
     int t;cin>>t;


    cout<<search(root,t)<<endl;

    cout<<"Find Using Level Order Traversal Method : ";
    cout<<find(root,t)<<endl;


   }

}
