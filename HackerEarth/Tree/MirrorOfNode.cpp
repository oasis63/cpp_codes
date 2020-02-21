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


// changed version of previous insert

void insert2(Node* root,int parent,int child,char pos){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->value == parent){
            if(pos == 'L'){
                temp->left = newNode(child);
            }else{
                temp->right=newNode(child);
            }
            break;
        }

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}



int findMirrorRec(int target, Node* left,Node* right)
{

    if (left==NULL || right==NULL)
        return 0;

    if (left->value == target)
        return right->value;

    if (right->value == target)
        return left->value;


    int mirror_val = findMirrorRec(target,left->left,right->right);

    if (mirror_val)
        return mirror_val;


    findMirrorRec(target, left->right, right->left);
}


int findMirror(Node* root, int target)
{
    if (root == NULL)
        return 0;
    if (root->value == target)
        return target;
    return findMirrorRec(target, root->left, root->right);
}



int main(){

    Node *root = newNode(1);
    int n,q,p,c;
    char pos;
    cin>>n>>q;

    while(--n){
        cin>>p>>c;
        cin>>pos;
        insert2(root,p,c,pos);
    }



    while(q--){
        int target;cin>>target;

        int mirror = findMirror(root, target);

        if (mirror)
            cout<<mirror<<endl;
        else
            cout<<-1<<endl;

    }


}

