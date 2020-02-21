#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;

Node* newNode(int key)
{
    Node* n = new Node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;

}

// recursive function to find mirror of Node
int findMirrorRec(int target, struct Node* left,struct Node* right)
{
    /* if any of the Node is none then Node itself
       and decendent have no mirror, so return
       none, no need to further explore! */
    if (left==NULL || right==NULL)
        return 0;

    /* if left Node is target Node, then return
       right's key (that is mirror) and vice
       versa */
    if (left->key == target)
        return right->key;

    if (right->key == target)
        return left->key;

    // first recur external Nodes
    int mirror_val = findMirrorRec(target,left->left,right->right);

    if (mirror_val)
        return mirror_val;

    // if no mirror found, recur internal Nodes
    findMirrorRec(target, left->right, right->left);
}

// interface for mirror search
int findMirror(struct Node* root, int target)
{
    if (root == NULL)
        return 0;
    if (root->key == target)   // root of the tree
        return target;
    return findMirrorRec(target, root->left, root->right);
}

// Driver
int main(){

    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->right = newNode(6);
    root->left->left = newNode(7);
    root->left->left->right = newNode(10);
    root->right->right=newNode(4);
    root->right->left=newNode(5);
    root->right->left->left=newNode(9);
    root->right->left->right=newNode(8);



    // target Node whose mirror have to be searched
    int target = 10;

    int mirror = findMirror(root, target);

    if (mirror)
        printf("Mirror of Node %d is Node %d\n",
                                    target, mirror);
    else
        printf("Mirror of Node %d is NULL!\n", target);
}
