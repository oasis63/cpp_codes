// directed Graph using C++ stl List

#include<bits/stdc++.h>
using namespace std;


class Graph{
    int v;
    list<int> *adj;  // pointer to list<int> type
public:
    Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int src,int dest){
        adj[src].push_back(dest);
    }

    void display();
};

void Graph::display(){
     for(int i=0;i<v;i++){
         list <int>:: iterator il = adj[i].begin();


          while(il != adj[i].end())
          {
                cout<<*il<<" ";
                il ++;
          }

          cout<<endl;
     }
}


int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);


    g.display();


}
