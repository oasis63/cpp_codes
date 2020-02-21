// tree data structure

// delete function is not working properly ,, work on it

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left=NULL;
        right=NULL;
    }
};

Node* newNode(int v){
    Node* node = new Node(v);
    return node;
}

// DLR

void preorder(Node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// preorder without recursion

void itrPreorder(Node* root){
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();  s.pop();

        cout<<temp->value<<" ";

        if(temp->right)
            s.push(temp->right);
        if(temp->right)
            s.push(temp->left);
    }
}

// level order traversal

void lvlT(Node* root){

    if(root==NULL)
        return;

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

// element insertion in binary tree  using level order traversal

void insert(Node* root,int value){
    queue<Node*> q;

    if(root==NULL){
        root=newNode(value);
        return;
    }

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->left)
            q.push(temp->left);
        else{   // if the left child is null we can insert here
                temp->left = newNode(value);
                return;
        }

        if(temp->right)
            q.push(temp->right);
        else{  // if right child is null
            temp->right = newNode(value);
            return;
        }
    }
}

int height(Node* root){
    if(root==NULL)
        return 0;
    else{

        int lheight = height(root->left);
        int rheight = height(root->right);

        if(lheight > rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

int noOfElements(Node* root){
    if(!root)
        return 0;
    else
        return ( noOfElements(root->left) + 1 + noOfElements(root->right));
}

// no of elements using level order traversal

int count(Node* root){
    int c=0;
    if(root==NULL)
        return c;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        c++;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return c;
}

// level order traversal in reverse order

void lvlTinReverse(Node* root){
    if(root==NULL)
        return;
    stack<Node*>s;
    queue<Node*>q;

    q.push(root);

    while(!q.empty()){

        Node* temp = q.front(); q.pop();

        if(temp->right)
            q.push(temp->right);

        if(temp->left)
            q.push(temp->left);
        s.push(temp);
    }

    // printing the elements

    while(!s.empty()){
        cout<<s.top()->value<<" ";s.pop();
    }

}

void deleteBT(Node* root){
    if(root==NULL)
        return;

    // first deleting the subtrees

    deleteBT(root->left);
    deleteBT(root->right);

    delete root;

}

Node* deepestNode(Node* root){
    Node* temp;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        temp = q.front(); q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return temp;

}



Node* find(Node* root,int val){

    if(root==NULL)
        return NULL;
    else if(root->value == val)
        return root;
    else{
        // finding in the sub trees
            Node* rL = find(root->left,val);

            if(rL)
                return rL;
            else
                return(find(root->right,val));
    }

}

//  parent of the last Deepest node





int  deleteNode(Node* root,int val){
    // searching the node of the element
    Node* delNode = find(root,val);

    if(delNode==NULL)  // element is not present
            return 0;


    // deepest node to be deleted
    Node* deepNode = deepestNode(root);

    delNode->value = deepNode->value;

    // freeing the deepest node of the tree


    queue<Node*> q;

    q.push(root);

    Node* temp;

    while(!q.empty()){
        temp = q.front(); q.pop();

        if(temp->right == deepNode){
            delete temp->right;
            temp->right = NULL;
            cout<<"\ntemp->right : ";
            cout<<temp->value<<endl;
            break;
        }
        else  if(temp->left == deepNode ){
            delete temp->left;
            temp->left = NULL;
            cout<<"\ntemp->left : ";
            cout<<temp->value<<endl;
            break;
        }


        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return 1;
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
    root->right->right->left=newNode(9);
    root->right->right->right=newNode(10);
    //root->right->right->right->right=newNode(11);

     cout<<"\nDeepest Element in the tree : "<<deepestNode(root)->value<<endl;

    cout<<"\nLevel Order Traversal Before Deletion\n"<<endl;
    lvlT(root);

    int value = deleteNode(root,4);

    cout<<"\nDeleted Node :" << value <<endl;

    cout<<"\nLevel Order Traversal After Deletion \n"<<endl;
    lvlT(root);

    cout<<"\nDeepest Element in the tree : "<<deepestNode(root)->value<<endl;

    deleteBT(root);
}
