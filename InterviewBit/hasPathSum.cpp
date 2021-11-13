// tree data structure

#include<bits/stdc++.h>
using namespace std;

int imax=INT_MIN;

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

void zigzag(Node* root){

    bool righToLeft = true;
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        Node* temp = currentLevel.top();
        currentLevel.pop();

        if(temp){

            cout<<temp->value<<"  ";


            if(righToLeft){
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }else{
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if(currentLevel.empty()){
            righToLeft = !righToLeft;
            swap(currentLevel,nextLevel);

        }
    }

    cout<<"\n"<<endl;
}

bool hasPathSum(Node* root,int sum ){

//    cout<<"executed"<<endl;

    if(!root)
        return false;

    if(root->left == NULL && root->right == NULL){
        if((sum-root->value)==0)
            return true;
        else
            return false;
    }


    bool retLeft=false;
    bool retRight = false;

    if(root->left){
        retLeft = hasPathSum(root->left,sum-root->value);
    }

    if(root->right){
        retRight = hasPathSum(root->right,sum-root->value);
    }

    return retLeft || retRight;
}

int main(){


    Node* root=new Node(5);
    root->left= new Node(4);
    root->right = new Node(8);
    root->left->left=new Node(11);
    root->left->left->left=new Node(7);
    root->left->left->right=new Node(2);
    root->right->left=new Node(13);
    root->right->right=new Node(4);
    root->right->right->right=new Node(1);


//    zigzag(root);


    int sum = 22;

    cout<<hasPathSum(root,sum)<<endl;

    return 0;
}
