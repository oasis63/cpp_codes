// BFS  traversal from given source vertex
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *adj; // array of list is needed
    bool isCyclicUtil(int src, bool visited[], int parent);
public:
    Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int src,int dest);
    void printGraph();
    bool isTree();

};

void Graph::addEdge(int src,int dest){   // directed edge
    adj[src].push_back(dest);    
}

void Graph::printGraph(){
    for(int i=0;i<v;i++){
        list<int>:: iterator iter= adj[i].begin();

        while(iter!=adj[i].end()){
            cout<<*iter<<" ";
            iter ++;
        }
        cout<<endl;

    }
}




bool Graph::isCyclicUtil(int src, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[src] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[src].begin(); i != adj[src].end(); ++i)
    {
        if (!visited[*i])                   // DFS used
        {
           if (isCyclicUtil(*i, visited, src))
              return true;
        }
        else if (*i != parent)
           return true;
    }
    return false;
}


bool Graph::isTree()
{

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    if (isCyclicUtil(0, visited, -1))
             return false;

    // If we find a vertex which is not reachable from 0
    // (not marked by isCyclicUtil(), then we return false
    for (int u = 0; u < v; u++)
        if (!visited[u])
           return false;

    return true;
}

int main(){

    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);

    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

    return 0;


}
