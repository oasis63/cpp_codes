#include<bits/stdc++.h>
using namespace std;

class Graph{
int vertices;
vector<pair<int,int>> *adj;  // array of adjacency list with weight
public:
    Graph(int v){ 
        vertices=v;
        adj = new vector<pair<int,int>>[v];
    }

    void addEdge(int src,int dest,int weight);
    void printGraph();
    int isCycle();
};

// we can consider parent as array of subsets
// finding the subset where i is present
int find(int parent[],int i){
    if(parent[i] ==  -1)
        return i;
    else
        return find(parent,parent[i]);
}

void Union(int parent[],int x,int y){
    int xset = find(parent,x);
    int yset = find(parent,y);

    parent[xset]=yset;
}

int Graph::isCycle(){

    int *parent = new int[vertices];

    for(int i=0;i<vertices;i++)   //each vertex as a single set with parent = -1
        parent[i]=-1;


    for(int i=0;i<vertices;i++){

        for(int j=0;j<adj[i].size();j++){
            int x = find(parent,i);       // finding the subset
            int y = find(parent,adj[i][j].first);    // finding the subset

            if(x==y){
                cout<<"\n\tCycle occurs on vertex  : "<< i<<" " <<adj[i][j].first<<endl;
                return 1;
            }
            Union(parent,x,y);
        }
    }

    return 0;
}

//Undirected Weighted Graph
void Graph::addEdge(int src,int dest,int weight){
    adj[src].push_back(make_pair(dest,weight));
    adj[dest].push_back(make_pair(src,weight));
}

void Graph::printGraph(){
    for(int i=0;i<vertices;i++){
        cout<<"Source Node is : "<<i<<endl;
        for(int j=0;j<adj[i].size();j++){
            cout<<"\tNext Node : "<<adj[i][j].first<<"   Weight of the path :  "<<adj[i][j].second<<endl;
        }
    }
}


int main(){

    Graph g(4);
    g.addEdge(0, 1,5);
    g.addEdge(0, 2,6);
    g.addEdge(1, 2,10);
    g.addEdge(2, 3,11);

    cout<<"\n Since the graph is Undirected .. so it will always have cycle "<<endl;

    if(g.isCycle()){
        cout<<"Has Cycle"<<endl;
    }else{
        cout<<"Do not have Cycle"<<endl;
    }

}


