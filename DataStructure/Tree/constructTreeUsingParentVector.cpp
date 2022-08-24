#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 


void printVector(vector<int> vect){
    int n = vect.size();
    for(int i=0;i<n;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

class Node{ 
    public:
        int value;
        Node* left;
        Node* right;
        // Node(){}
        Node(int key){
            value = key;
            left = NULL;
            right = NULL;
        }
};

// LDR
void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}
// DLR
void preorder(Node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
// LRD
void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<" ";
    }
}
// level order traversal 
void lot(Node* root){
    queue<Node*> q;  // FIFO
    q.push(root);
    int h_flag = 0;

    while(!q.empty()){
        Node* temp = q.front();q.pop();
        cout<<temp->value<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp -> right)
            q.push(temp->right);
    }
    cout<<"\nlot : Height : " << h_flag<<endl;
}

int height(Node* root){
    if(!root)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight+1,rHeight+1);
}

int maxRec(Node* root){

    int mx = INT_MIN,root_val,right_max,left_max;

    if(root){
        root_val = root->value;
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

void printListMap(map<int, list<int>> mlist){
    //  map <int,string>:: iterator itr = m1.begin();
    //  map<int,list<int>>
    map<int,list<int>>::iterator itr = mlist.begin();


    while (itr != mlist.end()){
        cout << itr->first << " : " <<"\t---->  ";
        list<int> l1 = itr->second;
        
        list <int>:: iterator il = l1.begin();
        while(il != l1.end()){
                cout<<*il<<" ";
                il ++;
        }
        cout<<endl;
        itr++;
    }
}

void printList(list<int> l1){
    // cout<"List : "<<;
    cout<<" List :  ";
    list <int>:: iterator il = l1.begin();
    while(il != l1.end()){
            cout<<*il<<" ";
            il ++;
    }
    cout<<" : " <<endl;
}

void childToParent(Node* root,list<int> &currentList,int parentValue){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();q.pop();
        if (temp->value == parentValue){
            list<int>::iterator il = currentList.begin();
            bool flag = true;
            while (il != currentList.end()){
                // cout << *il << " ";
                if (flag)
                    temp->left = new Node(*il);
                else
                    temp->right = new Node(*il);
                il++;
                flag = !flag;
            }
            break;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }

}

void constructTreeUtil(Node* root,map<int,list<int>> link,list<int> currentList,int parentValue){
    if(currentList.size() == 0){
        return;
    }
    // printList(currentList);
    childToParent(root,currentList,parentValue);
    list<int>::iterator lit = currentList.begin();
    while(lit != currentList.end()){
        constructTreeUtil(root,link,link[*lit],*lit);
        lit++;
    }
}

Node* constructTreeUsingParentNodes(vector<int> parent,Node* treeNode){
    map<int,list<int>> mapLink; // parent, children 
    int n = parent.size();
    for(int i=0;i<n;i++){
        mapLink[parent[i]].push_back(i);
        if(parent[i] == -1)
            treeNode = new Node(i);
    }
    // printListMap(mapLink);
    constructTreeUtil(treeNode,mapLink,mapLink[treeNode->value],treeNode->value);
    // inorder(treeNode);
    return treeNode;
}


int main(){
    Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->right->right->right = new Node(8);
    // root->right->right->right->right = new Node(9);
    // root->right->right->right->right->left = new Node(10);
    // root->right->right->right->right->right = new Node(11);

    // inorder(root);cout<<endl;
    // preorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // lot(root);cout<<endl;

    // cout<<"height : " <<height(root)<<endl;
    // cout<<"maxValue : "<<maxRec(root)<<endl;
    // vector<int> parent {1, 5, 5, 2, 2, -1, 3};
     vector<int> parent  {-1, 0, 0, 1, 1, 3, 5};

    // vector<int> parent {-1,0,1};
    vector<int> waterLavel {0,1,-1};
    int overhydratedPenalty = 2; 
    int underhydratedPenalty = 1;

    Node *treeNode = NULL;
    treeNode = constructTreeUsingParentNodes(parent,treeNode);

    cout<<"\nInorder Traversal"<<endl;

    inorder(treeNode);

    return 0;
}