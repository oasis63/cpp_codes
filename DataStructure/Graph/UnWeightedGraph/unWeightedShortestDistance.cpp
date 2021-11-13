// BFS  traversal from given source vertex
// shortest distance in Unweighted directed graph

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
    void unweightedShortedDistance(int src);

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
}


// finding shortest distance from a src vertex to other vertices

void Graph::unweightedShortedDistance(int src){

    queue<int> q;
    int curr;    // current vertex and it's children vertices

    q.push(src);

    int distance[v];
    int parentVertex[v];

    for(int i=0;i<v;i++){
        parentVertex[i] = -1;
    }



    for(int i=0;i<v;i++){
        distance[i] = -1;   // initially no distance
    }

    distance[src] = 0;   // distance from itself is zero(0)

    while(!q.empty()){
        curr = q.front(); q.pop();

        cout<<curr<<" ";

        list<int>:: iterator it;

        for( it=verList[curr].begin();it!=verList[curr].end();it++){
            if(distance[*it] == -1){
                distance[*it] = distance[curr] + 1;
                parentVertex[*it] = curr;
                q.push(*it);
            }
        }
    }

    cout<<"\nDistance of the vertices from the vertex "<< src << endl;

    cout<<"Vertex \t  Distance \t Previous Vertex "<<endl;

    for(int i=0;i<v;i++){
        cout<<i<<"\t\t"<<distance[i]<<"\t\t"<<parentVertex[i]<<endl;
    }



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

    //system("pause");
}
