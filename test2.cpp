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

void zigzag(Node* root,vector<vector<int>> &ans){

    bool righToLeft = true;
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    currentLevel.push(root);

    vector<int> vect;

    while(!currentLevel.empty()){
        Node* temp = currentLevel.top();
        currentLevel.pop();

        if(temp){

            cout<<temp->value<<"  ";
            vect.push_back(temp->value);

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
            ans.push_back(vect);
            vect.clear();
        }
    }

    cout<<"\n"<<endl;
}



int main(){

    Node* root=NULL;
    root=new Node(3);
    root->left= new Node(1);
    root->right = new Node(5);
    root->left->left=new Node(0);
    root->left->right=new Node(2);
    root->right->left=new Node(4);
    root->right->right=new Node(6);


    vector<vector<int>> vect;

    zigzag(root,vect);


    for(int i=0;i<vect.size();i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
