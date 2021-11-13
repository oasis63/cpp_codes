#include<bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure

class BinaryTreeNode {
    public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode * insert(BinaryTreeNode * root,int val){

    if(root == NULL){
        root = new BinaryTreeNode(val);
    }else if( val > root->data){
        return insert(root->right,val);
    }else if(val < root->data){
        return insert(root->left,val);
    }

    return root;
}

int countNodes(BinaryTreeNode *root) {
    if(root == NULL){
            return 0;
    }
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

void printNodesSumToS(BinaryTreeNode*root, int s) {
    if(root == NULL) {
            return;
    }

    int totalCount = countNodes(root);
    int count = 0;

    stack<BinaryTreeNode*> inorder;
    stack<BinaryTreeNode*> revInorder;

    BinaryTreeNode* temp = root;

    while(temp!=NULL){
        inorder.push(temp);
        temp=temp->left;
    }

    temp = root;
    while(temp!=NULL){
        revInorder.push(temp);
        temp=temp->right;
    }

    while(count < totalCount - 1){
        BinaryTreeNode *top1 = inorder.top();
        BinaryTreeNode *top2 = revInorder.top();

        if(top1->data + top2->data == s){
            cout<<top1->data<<" "<<top2->data<<endl;


        BinaryTreeNode *top = top1;
        inorder.pop();
        count++;

        if(top -> right != NULL){
            top = top->right;
            while(top!=NULL){
                inorder.push(top);
                top=top->left;
            }
        }

        top = top2;
        revInorder.pop();
        count++;

        if(top->left != NULL){
            top = top->left;
            while(top!=NULL){
                revInorder.push(top);
                top=top->right;
            }
        }

        }else if(top1->data + top2->data > s){
            BinaryTreeNode *top = top2;
            revInorder.pop();
            count++;

            if(top->left != NULL){
                top = top->left;
            }

        }

    }



}



void inorder(BinaryTreeNode*root,priority_queue<int,vector<int>,greater<int>> &pq){
    if(root){
       pq.push(root->data);
        inorder(root->left,pq);
        inorder(root->right,pq);
    }
}

int kthSmallestNodeBST1(BinaryTreeNode* root, int k) {
		// Write your code here
	priority_queue<int,vector<int>,greater<int>> pq;
    inorder(root,pq);

    while(!pq.empty() && k > 1){
        pq.pop();
        k--;
    }
    return pq.top();
}


//  kthSmallestNodeBST Method2
// Not working properly work over ti 

int kthSmallestNodeBST2(BinaryTreeNode* root,int k){

    if(root == NULL){
        return INT_MIN;
    }

    int leftCount = countNodes(root->left);

    if(leftCount >= k){
        return kthSmallestNodeBST2(root->left,k);
    }else if(leftCount == k-1){
        return root->data;
    }else{
        return kthSmallestNodeBST2(root->right,k-leftCount-1);;
    }
}


int main(){

    BinaryTreeNode* root = NULL;
    root=insert(root,8);
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,7);

    int s = 12;

//    printNodesSumToS(root,s);

    cout<<"Kth Smallest Nodes in BST by Method 1 :";
    cout<<kthSmallestNodeBST1(root,4)<<endl;

    cout<<"Kth Smallest Nodes in BST by Method 2 :";
    cout<<kthSmallestNodeBST2(root,4)<<endl;


    return 0;
}
