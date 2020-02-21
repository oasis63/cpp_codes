// bfs in graph
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    list<int> *adj; 
    void dfsUtil(int src,bool *);
public:
    Graph(int v){
        vertices=v;
        adj = new list<int>[v];
    }

    void addEdge(int src,int dest);
    void printGraph();
    void bfs(int src);
    void dfs(int src);
};

void Graph::addEdge(int src,int dest){    // directed graph
    adj[src].push_back(dest);
}

void Graph::printGraph(){
    for(int i=0;i<vertices;i++){
        list<int>::iterator it = adj[i].begin();
        while(it!=adj[i].end()){
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
    }
}


void Graph::bfs(int src){

// similar to level order traversal in Tree 

    bool *visited = new bool[vertices];

    for(int i=0;i<vertices;i++)
        visited[i]=false;

    queue<int>q;
    q.push(src);

    visited[src]=true;

    while(!q.empty()){

        int value = q.front();q.pop();

        cout<<value<<" ";

        list<int>::iterator itr;
        for(itr=adj[value].begin();itr!=adj[value].end();itr++){
            if(!visited[*itr]){
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }

    cout<<"================"<<endl;

}

void Graph::dfsUtil(int src,bool *visited){

    visited[src]=true;

    cout<<src<<" ";

    list<int>::iterator itr ;

    for(itr=adj[src].begin();itr!=adj[src].end();itr++){
        if(!visited[*itr])
            dfsUtil(*itr,visited);
    }

}



void Graph::dfs(int src){
    bool *visited = new bool[vertices];
    for(int i=0;i<vertices;i++)
        visited[i]=false;    // initially none of the vertex is visited

    dfsUtil(src,visited);

}


int main(){
    
    Graph graph(5);   // graph with 5 vertices
    graph.addEdge(0,1);
    graph.addEdge(0,4);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(1,4);
    graph.addEdge(2,3);
    graph.addEdge(3,4);

    graph.printGraph();

    cout<<"\n========BFS=======\n"<<endl;

    graph.bfs(0);

    cout<<"\n========DFS=======\n"<<endl;
    graph.dfs(0);

}
