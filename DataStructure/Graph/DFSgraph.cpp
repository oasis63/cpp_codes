// BFS  traversal from given source vertex
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *verList; // array of list is needed
    void dfsUtil(int src,bool visited[]);
public:
    Graph(int v){
        this->v = v;
        verList = new list<int>[v];
    }

    void addEdge(int src,int dest);
    void printGraph();
    void dfs(int src);

};

void Graph::addEdge(int src,int dest){
    verList[src].push_back(dest);
}

void Graph::printGraph(){
    for(int i=0;i<v;i++){
        list<int>:: iterator iter= verList[i].begin();

        while(iter!=verList[i].end()){
            cout<<*iter<<" ";
            iter ++;
        }
        cout<<endl;

    }
}

/* this is of the member method of the Given Class
        .. so it knows the number of vertex
*/

void Graph::dfsUtil(int src,bool visited[]){
 
    visited[src] = true;
    cout<<src<<" ";

    list<int>:: iterator it;

    for( it=verList[src].begin();it!=verList[src].end();it++){
        if(!visited[*it])
            dfsUtil(*it,visited);   // recursive call to next element of the adjacent list
    }

}

void Graph::dfs(int src){

    // array to check whether the given vertex is visited or not

    bool *visited = new bool[v];

    for(int i=0;i<v;i++)
        visited[i] = false; // no vertex is visited at first

    dfsUtil(src,visited);
}

int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.printGraph();

    cout<<"DFS Traversal "<<endl;
    g.dfs(2);


}

