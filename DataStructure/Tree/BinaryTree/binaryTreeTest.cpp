// tree
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int key){
        data = key;
        left = NULL;
        right= NULL;
    }
};

Node* newNode(int val){
    Node* node = new Node(val);
    return node;
}

//LDR
void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


void pre_non(Node* root){
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top(); s.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
}

int height(Node* root){
    if(root==NULL)
        return 0;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        return lheight>rheight?(lheight+1):(rheight+1);
    }

}


// level order traversal

void lot(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

}

// finding the maximum element in the tree

int maxElem(Node* root){
    int mx = INT_MIN;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();q.pop();

        if(temp->data > mx)
            mx=temp->data;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return mx;
}


int maxRec(Node* root){

    int mx = INT_MIN,root_val,right_max,left_max;

    if(root){
        root_val = root->data;
        left_max = maxRec(root->left);
        right_max = maxRec(root->right);
        if(left_max > right_max)
            mx = left_max;
        else
            mx = right_max;

        if(root_val > mx)
            mx= root_val;
    }

    return mx;
}

//Use Level Order Traversal To insert into The tree .. insert the value
//wherever a node has its Left or Right child as NULL


void  insertValue(Node* root,int val){

    Node* node = newNode(val);

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();q.pop();

        if(temp->left)
            q.push(temp->left);
        else{
            temp->left = node;
            return;
        }


        if(temp->right)
            q.push(temp->right);
        else{
            temp->right = node;
            return;
        }
    }


}

// finding deepest node in the tree

Node* deepestNode(Node* root){

    Node* temp;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return temp;
}

Node* deleteNode(Node* root,int val){

    // find the deepest node in the tree
    Node* deepNode = deepestNode(root);

    Node* temp;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();q.pop();

        // replace the node to be deleted with the deepest node
        if(temp->data == val){
            temp->data = deepNode->data;
            break;
        }

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    queue<Node*> emp;
    swap(q,emp);   // clearing the queue q using empty queue

    q.push(root);

    while(!q.empty()){
        temp = q.front();q.pop();


        if(temp->left == deepNode && deepNode->left == NULL && deepNode->right == NULL){
            temp->left = NULL;
            break;
        }
        else{
            q.push(temp->left);
        }

        if(temp->right == deepNode && deepNode->left == NULL && deepNode->right == NULL){
            temp->right = NULL;
            break;
        }
        else{
            q.push(temp->right);
        }

    }



    return root;
}

// Finding number of leave of a tree

int numberOfLeaves(Node* root){
    int ans = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();q.pop();

        if(temp->left == NULL && temp->right == NULL)
            ans++;
        else{
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }
    return ans;
}


Node* lca(Node* root, Node* node1,Node* node2){
    Node *l,*r;

    if(root==NULL)
        return root;
    if(root == node1 || root==node2)
        return root;

    l = lca(root->left,node1,node2);
    r = lca(root->right,node1,node2);

    if(l&&r)
        return root;
    else if(l)
        return l;
    else
        return r;
}

int main(){
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    lot(root);

    cout<<endl;

    cout<<lca(root,root->left,root->right->left)->data<<endl;

    //insertValue(root,434);

    //lot(root);

    //cout<<"\n Deepest Node " << deepestNode(root)->data<<endl;

    //root = deleteNode(root,4);
    //lot(root);

    //cout<<"\n Number of Leaves "<<numberOfLeaves(root)<<endl;
}


