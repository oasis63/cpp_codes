#include<bits/stdc++.h>
using namespace std;

//int maxLen  = 1000;

class Child{
public:
    int value;
    int position;

    Child(int v,int p){
        value = v;
        position=p;
    }

};

vector<Child>children[1000];

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




void lvlTrans(Node* root){
    if(root==NULL){
        cout<<"Empty Tree"<<endl;
        return;
    }

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

// changed version of previous insert




void insert2(Node* root,int parent,int parentPosition,int child,int childPostion){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front(); q.pop();

        if(temp->value == parent){
                if(temp->left==NULL){
                    temp->left=newNode(child);
                    Child obj(child,childPostion);
                    children[parentPosition].push_back( obj);
                    return;
                }else if(temp->right==NULL){
                    temp->right=newNode(child);
                    Child obj(child,childPostion);
                    children[parentPosition].push_back( obj);
                    return;
                }
        }

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}



int main(){


    int n,minSum;
    cin>>n>>minSum;

    int number[n],parent[n];

    for(int i=0;i<n;i++){
        cin>>number[i];
    }

    parent[0]=number[0];

    for(int i=1;i<n;i++){
        cin>>parent[i];
    }


    Node *root = newNode(number[0]);

    for(int i=1;i<n;i++){
        insert2(root,number[parent[i]-1],(parent[i]-1),number[i],i);
    }


//
//    insert2(root,1,2);
//    insert2(root,1,5);
//    insert2(root,2,3);
//    insert2(root,2,4);


    //lvlTrans(root);

    // pushing the children of a parent to the list of children of the every upper parent


    for(int i=0;i<n;i++){
        for(int j=0;j<children[i].size();j++){
            int childIndex = children[i][j].position;
            for(int k=0;k<children[childIndex].size();k++){
                children[i].push_back(children[childIndex][k]);
            }
        }
    }


//
//    for(int i=0;i<n;i++){
//        for(int j=0;j<root->children[i].size();j++){
//            cout<<"\t"<<root->children[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    int ans=0;


     for(int i=0;i<n;i++){
        for(int j=0;j<children[i].size();j++){
            //cout<<"\t"<<root->children[i][j]<<" ";
            for(int k=j+1;k<children[i].size();k++){
                int temp = number[i] + children[i][j].value + children[i][k].value;
                if(temp >= minSum){
                    //cout<<number[i]<<" "<<children[i][j].value<<" "<<children[i][k].value<<endl;
                    ans++;
                }
            }
        }
    }

    cout<<ans<<endl;

}



