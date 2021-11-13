//delete node from a tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;


Node* newNode(int value){
    Node* n = new Node();
    n->data =value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root,int data){
    if(root==NULL)
        root=newNode(data);
    else if( data > root->data)
        root->right = insert(root->right,data);
    else if( data < root->data)
        root->left = insert(root->left,data);
    return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void lvl(Node* root ){

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }


}

// Return the maximum element between a Node
// and its given ancestor.
int maxelpath(Node *q, int x){

    Node *p = q;

    int mx = INT_MIN;

    // Traversing the path between ansector and
    // Node and finding maximum element.
    while (p -> data != x)
    {
        if (p -> data > x)
        {
            mx = max(mx, p -> data);
            p = p -> left;
        }
        else
        {
            mx = max(mx, p -> data);
            p = p -> right;
        }
    }

    return max(mx, x);
}

// Return maximum element in the path between
// two given Node of BST.
int maximumElement(Node *root, int x, int y)
{
    Node *p = root;

    // Finding the LCA of Node x and Node y
    while ((x < p -> data && y < p -> data) ||
        (x > p -> data && y > p -> data))
    {
        // Checking if both the Node lie on the
        // left side of the parent p.
        if (x < p -> data && y < p -> data)
            p = p -> left;

        // Checking if both the Node lie on the
        // right side of the parent p.
        else if (x > p -> data && y > p -> data)
            p = p -> right;
    }

    // Return the maximum of maximum elements occur
    // in path from ancestor to both Node.
    return max(maxelpath(p, x), maxelpath(p, y));
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
    root=insert(root,11);

    lvl(root);

    cout<<endl;

    cout<<"\n Maximum element between 0 and 11 " << maximumElement(root , 0 ,  11)<<endl;
}
