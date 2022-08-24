#include<bits/stdc++.h>
using namespace std;

// hyderated and underhyderated penalty 

/* 
 // input

 3
-1
0
1
3
0
1
-1
2
1


 */


class Node{
    public:
        int data;
        Node* left,*right;
        Node(int t){
            data = t;
            left = right = NULL;
        }
};

map<int,int> waterLevelMap; // index, water level

int solveUtil(vector<int> parent, vector<int> waterLevel, int overhydratedPenalty, int underhydratedPenalty,int ind) {
    int totalNodes = waterLevel.size();
    
    
    
    
}


void childToParent(Node* root,list<int> &currentList,int parentValue){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();q.pop();
        if (temp->data == parentValue){
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

void constructTreeUsingParentNodes(vector<int> parent){
    Node* treeNode;
    map<int,list<int>> mapLink; // parent, children 
    int n = parent.size();
    for(int i=0;i<n;i++){
        mapLink[parent[i]].push_back(i);
        if(parent[i] == -1)
            treeNode = new Node(i);
    }
    // printListMap(mapLink);
    constructTreeUtil(treeNode,mapLink,mapLink[treeNode->data],treeNode->data);
    // inorder(treeNode);
    // return treeNode;
    //  n  == total number of nodes in the tree
    for(int i=0;i<n;i++){
        // pouring wate at the index/ node i
        

    }
}


// Complete the minimumPouringWaterPenalty function below.
int minimumPouringWaterPenalty(vector<int> parent, vector<int> waterLevel, int overhydratedPenalty, int underhydratedPenalty) {
    int totalNodes = waterLevel.size();
    int ans = INT16_MAX;
    // Node *root = createTree(parent, totalNodes);
    for(int i =0;i<totalNodes;i++){
        waterLevelMap.insert(make_pair(i,waterLevel[i]));
    }
    // for(int i=0;i<totalNodes;i++){
    //     int penalty = solveUtil(parent,waterLevel,overhydratedPenalty,underhydratedPenalty,i);
    //     ans = min(penalty,ans);
    // }

    // for(int i=0;i<totalNodes;i++){

    // }


    return ans;
}



int main(){
    vector<int> parent {-1,0,1};
    vector<int> waterLavel {0,1,-1};
    int overhydratedPenalty = 2; 
    int underhydratedPenalty = 1;

    cout<<minimumPouringWaterPenalty(parent,waterLavel,
        overhydratedPenalty,underhydratedPenalty)<<endl;

    return 0;
}