// BFS  traversal from given source vertex
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *verList; // array to list is needed
public:
    Graph(int v){
        this->v = v;
        verList = new list<int>[v];
    }

    void addEdge(int src,int dest);
    void printGraph();
    void bfs(int src);

};

void Graph::addEdge(int src,int dest){    // undirected graph
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

void Graph::bfs(int src){

    // similar to level order traversal in Tree 

    // array to check whether the given vertex is visited or not

    bool *visited = new bool[v];

    for(int i=0;i<v;i++)
        visited[i] = false; // no vertex is visited at first

    queue<int> q;
    q.push(src);

    visited[src] = true;

    while(!q.empty()){
        int s = q.front();q.pop();
        cout<<s<<" ";

        list<int>:: iterator it;

        for( it=verList[s].begin();it!=verList[s].end();it++){
            if(!visited[*it]){
                visited[*it] =  true;
                q.push(*it);
            }
        }

    }


    /*
        visited if the vertex is pushed into
        the queue. from where we can print
        the value;
    */

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

    cout<<"BFS Traversal "<<endl;
    g.bfs(2);
    cout<<endl;
    //system("pause");
}
