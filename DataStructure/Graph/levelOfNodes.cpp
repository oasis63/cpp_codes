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

void Graph::addEdge(int src,int dest){
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

    bool *visited = new bool[vertices];

    int  level[vertices];

    for(int i=0;i<vertices;i++)
        visited[i]=false;

    queue<int>q;
    q.push(src);

    visited[src]=true;

    level[src] = 0;


    while(!q.empty()){
        int value = q.front();q.pop();

        cout<<value<<" ";

        list<int>::iterator itr;
        for(itr=adj[value].begin();itr!=adj[value].end();itr++){
            if(!visited[*itr]){
                visited[*itr] = true;
                q.push(*itr);
                level[*itr] = level[value]+1;

            }
        }
    }


    cout<<"\n======= Levels of Graph========="<<endl;

    for(int i=0;i<vertices;i++){
        cout<<level[i]<<" ";
    }


}




int main(){
    Graph graph(10);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(1,4);
    graph.addEdge(1,5);
    graph.addEdge(3,6);
    graph.addEdge(3,7);
    graph.addEdge(4,8);
    graph.addEdge(4,9);



    //graph.printGraph();

    graph.bfs(0);

    cout<<"\n========DFS=======\n"<<endl;
    //graph.dfs(0);

}
