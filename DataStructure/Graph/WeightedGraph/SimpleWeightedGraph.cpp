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

}; 

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


    g.printGraph();



}


