// bfs in graph
#include<bits/stdc++.h>
using namespace std;


void addEdge(list<int>*adj,int src,int dest){
    adj[src].push_back(dest);
}

void printGraph(list<int>*adj,int vertices){
    for(int i=0;i<vertices;i++){
        list<int>::iterator it = adj[i].begin();
        while(it!=adj[i].end()){
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
    }
}


void bfs(list<int>*adj,int src,int vertices){

// similar to

    int tag=0;

    bool *visited = new bool[vertices];

    for(int i=0;i<vertices;i++)
        visited[i]=false;

    queue<int>q;
    q.push(src);

    visited[src]=true;

    //cout<<"\tag="<<tag<<"--\n";

    while(!q.empty()){
        int value = q.front();q.pop();

        cout<<value<<" ";

        tag++;

        list<int>::iterator itr;
        for(itr=adj[value].begin();itr!=adj[value].end();itr++){
            if(!visited[*itr]){
                visited[*itr] = true;
                q.push(*itr);
                //cout<<"\tag="<<tag<<"--\n";
            }
        }
    }

    cout<<"================"<<endl;

}

void dfsUtil(list<int>*adj,int src,bool *visited,int vertices){

    visited[src]=true;

    cout<<src<<" ";

    list<int>::iterator itr ;

    for(itr=adj[src].begin();itr!=adj[src].end();itr++){
        if(!visited[*itr])
            dfsUtil(adj,*itr,visited,vertices);
    }

}



void dfs(list<int>*adj,int src,int vertices){
    bool *visited = new bool[vertices];
    for(int i=0;i<vertices;i++)
        visited[i]=false;    // initially none of the vertex is visited

    dfsUtil(adj,src,visited,vertices);

}


int main(){

    list<int> *adj = new list<int>[10];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,3,6);
    addEdge(adj,3,7);
    addEdge(adj,4,8);
    addEdge(adj,4,9);



    printGraph(adj,10);

    bfs(adj,0,10);

    cout<<"\n========DFS=======\n"<<endl;
    dfs(adj,0,10);

}
