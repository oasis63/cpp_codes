#include<bits/stdc++.h>
using namespace std;

class Graph{
int vertices;
list<int> *adj;  // array of adjacency list
public:
    Graph(int v){
        vertices=v;
        adj = new list<int>[v];
    }

    void addEdge(int src,int dest);
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
        list<int>::iterator itr = adj[i].begin();
        for(;itr!=adj[i].end();itr++){
            int x = find(parent,i);       // finding the subset
            int y = find(parent,*itr);    // finding the subset

            if(x==y){
                cout<<"\n\tCycle occurs on vertex  : "<< i<<" " <<*itr<<endl;
                return 1;
            }
            Union(parent,x,y);
        }
    }

    return 0;
}

void Graph::addEdge(int src,int dest){
    adj[src].push_back(dest);
}

void Graph::printGraph(){
    for(int i=0;i<vertices;i++){
        list<int>:: iterator iter= adj[i].begin();

        while(iter!=adj[i].end()){
            cout<<*iter<<" ";
            iter ++;
        }
        cout<<endl;

    }
} 


int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);

    g.printGraph();

    if(g.isCycle()){
        cout<<"Has Cycle"<<endl;
    }else{
        cout<<"Do not have Cycle"<<endl;
    }
}


