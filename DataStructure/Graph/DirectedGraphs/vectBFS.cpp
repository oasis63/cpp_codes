// directed Graph using C++ stl List

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
};

void Graph::display(){
     for(int i=0;i<v;i++){

         for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
         }

          cout<<endl;
     }
}

void Graph::bfs(int src){

// similar to

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

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    g.addEdge(2, 3);



    g.display();

    cout<<endl;

    g.bfs(1);


}
