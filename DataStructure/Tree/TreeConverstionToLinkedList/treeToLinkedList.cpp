#include<bits/stdc++.h>
using namespace std;


/*
    Complete Code ... Working properly
*/


int imax=INT_MIN;

class Nodell{
public:
    int data;
    Nodell *next;

    Nodell(int n){
        data = n;
        next = NULL;
    }
};

Nodell* newNodell(int d){
    Nodell* n = new Nodell(d);
    return n;
}

Nodell* insert(Nodell* head,int d){

    Nodell* n = newNodell(d);

    if(head==NULL){
        head=n;
        return head;
    }

    n->next=head;
    head=n;

    return head;
}

void print(Nodell* head){

        while(head){
            cout<<head->data<<" ";
            head=head->next;
        }
}

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

void inorder1(Node* root){   // LDR
    if(root){
        inorder1(root->left);
        cout<<root->value<<" ";
        inorder1(root->right);
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



//  working properly

Nodell* inorder(Node* root,Nodell* head){   // LDR

    if(root){

        head = inorder(root->left,head);

        //cout<<root->value<<" ";
        if(head==NULL ){
            head=newNodell(root->value);
            return head;
        }

        Nodell *n = newNodell(root->value);
        // insert the node at the end of the linked list
        Nodell* temp = head;

        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n;

        head = inorder(root->right,head);
    }

    return head;
}



int main(){
    Node* root=NULL;

    root = newNode(10);
    root->left = newNode(12);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right = newNode(15);
    root->right->left = newNode(36);

    Nodell* head = NULL;

    head = inorder(root,head);

    cout<<"Level Order Traversal Of Tree : \n\n\t";

    lvlT(root);

    cout<<"\n\nLinked List of the Tree : \n\n\t";

    print(head);

    cout<<endl;


}
