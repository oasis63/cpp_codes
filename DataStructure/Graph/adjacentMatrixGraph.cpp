// Graph Representation Using Adjacent Matrix

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    int **arr;
public:
    Graph(int v){
        this->v = v;
        arr = new int*[v];

        for(int i=0;i<v;i++){
            arr[i] = new int[v];
        }

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                arr[i][j] = 0;
            }
        }
    }

    void addEdge(int src,int dest);
    void printGraph();
};


void Graph::printGraph(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}


// we can also set the weight of the given edge

void Graph::addEdge(int src,int dest){
    arr[src][dest] = 1;
}

int main(){
    Graph g(5);

    cout<<"__---__ Implementation of Graph using Adjacent Matrix ___---____\n"<<endl;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.addEdge(4,3);

    g.printGraph();

    return 0;
}

