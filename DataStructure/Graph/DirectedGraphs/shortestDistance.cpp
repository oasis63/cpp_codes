#include<bits/stdc++.h>
using namespace std;


class Graph{
    int v;
    vector<int> *adj;  // pointer to list<int> tyep
public:
    Graph(int v){
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int src,int dest){
        adj[src].push_back(dest);
    }

    void bfs(int src);
    void display();
    void unweightedShortedDistance(int src);
};

void Graph::unweightedShortedDistance(int src){

   queue<int> q;
    q.push(src);

    int distance[v];
    int previousVertex[v];
    for(int i=0;i<v;i++){
        distance[i]=INT_MAX;
        previousVertex[i]=-1;
    }

    distance[src]=0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i=0;i<adj[curr].size();i++){
           
            if(distance[adj[curr][i]] > distance[curr]+1){
                distance[adj[curr][i]] = distance[curr]+1;
                previousVertex[adj[curr][i]]=curr;
                q.push(adj[curr][i]);
            } 
        }
    }

    cout<<"\nDistance of all the vertices from the vetext : "<< src <<endl;

    cout<<"Vertex \t Distance \t Previous Vertex "<<endl;

    for(int i=0;i<v;i++){
        cout<<i<<"\t\t"<<distance[i]<<"\t\t"<<previousVertex[i]<<endl;
    }


}

void Graph::display(){
     for(int i=0;i<v;i++){
        cout<<"Childeren of Node  "<<i<<":\t";
         for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
         }

          cout<<endl;
     }
}

void Graph::bfs(int src){

// similar to level order traversal

    bool *visited = new bool[v];

    for(int i=0;i<v;i++)
        visited[i]=false;

    queue<int>q;
    q.push(src);

    visited[src]=true;

    while(!q.empty()){
        int value = q.front();q.pop();

        cout<<value<<" ";

        for(int i=0;i<adj[value].size();i++){
            if(!visited[adj[value][i]]){
                visited[adj[value][i]] = true;
                q.push(adj[value][i]);
            }
        }
    }

    cout<<"================"<<endl;

}
 

int main(){

    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,3);
    graph.addEdge(1,4);
    graph.addEdge(1,3);
    graph.addEdge(2,0);
    graph.addEdge(2,5);
    graph.addEdge(4,6);
    graph.addEdge(3,6);
    graph.addEdge(3,5);
    graph.addEdge(6,5);


    graph.unweightedShortedDistance(2);

}
