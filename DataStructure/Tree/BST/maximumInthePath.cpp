#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        data=d;
        right=left=NULL;
    }
};

Node* newNode(int v){
    Node* n = new Node(v); // memory of type Node Class
    return n;
}

Node* insert(Node* root,int val){
    if(root==NULL)
        root=newNode(val);
    else if(val > root->data)
        root->right = insert(root->right,val);
    else if(val < root->data)
        root->left = insert(root->left,val);
    return root;
}

int height(Node* root){
    if(root==NULL)
        return 0;
    else{
        int l = height(root->left);
        int r = height(root->right);

        if(r > l)
            return(r+1);
        else
            return(l+1);

    }
}


int findMaxInPath(Node *q, int x)
{
    Node *p = q;
    int mx = -1;
    while(p->data != x)
    {
        if(p->data > x)
        {
            mx = max(mx, p->data);
            p = p->left;
        }
        else
        {
            mx = max(mx, p->data);
            p = p->right;
        }
    }
    return max(mx, x);
}
int findMax(Node* root,int x, int y)
{
    Node *p = root;
    while((x < p->data and y < p->data) or (x > p->data and y > p->data))
    {
        if(x < p->data and y < p->data)
            p = p->left;
        else if(x > p->data and y > p->data)
            p = p->right;
    }
    return max(findMaxInPath(p, x), findMaxInPath(p, y));
}

int main()
{
   int n;cin>>n;int val[n];
   for(int i=0;i<n;i++) cin>>val[i];
   int x,y;cin>>x>>y;
   Node* root=NULL;
   for(int i=0;i<n;i++){
       root=insert(root,val[i]);
   }

   int max=findMax(root,x,y);


   cout<<max<<endl;



}
