#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    list<int> *adj;
public:
    Graph(int v){
        vertices=v+1;
        adj = new list<int>[vertices];
    }

    void addEdge(int src,int dest);
    void printGraph();
    void myDfs(int src,int numTowers,bool *visited);
};

void Graph::addEdge(int src,int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
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


void Graph::myDfs(int src,int numTowers,bool *visited ){

    queue<int>q;
    q.push(src);
    visited[src]=true;

    //int temp = numTowers;

    while(!q.empty()){
        int value = q.front();q.pop();

        //cout<<value<<" ";


        list<int>::iterator itr ;

        for(itr=adj[value].begin();itr!=adj[value].end();itr++){
            if(!visited[*itr]  && numTowers > 0){
                //numTowers--;
                myDfs(*itr,numTowers-1,visited);
            }
        }

    }

}


int main(){

    int n,m,t;
    cin>>n>>m>>t;

    Graph graph(n);

    for(int i=0;i<m;i++){
        int s,d;
        cin>>s>>d;
        graph.addEdge(s,d);
    }

    int towers[n+1];

    for(int i=0;i<=n;i++)
        towers[i]=0;

    for(int i=0;i<t;i++){
        int city,nos;
        cin>>city>>nos;
        towers[city] = nos;   // number of cities
    }


    // if there is no road connecting any cities

    if(m==0){

        int count = 0;

        for(int i=0;i<=n;i++){
            if(towers[i]==0  && i!=0){
                count++;
            }
        }

        cout<<count<<endl;

        for(int i=0;i<=n;i++){
            if(towers[i]==0  && i!=0){
                cout<<i<<" ";
            }
        }



    }else{

        bool *visited = new bool[n+1];

        for(int i=0;i<=n;i++){
            visited[i] = false;
        }

        for(int i=0;i<=n;i++){

            if(towers[i]){
                    //cout<<"\nExecuted " << i<<towers[i]<<endl;
                graph.myDfs(i,towers[i],visited);
            }
        }

        int total = 0;

        for(int i=0;i<=n;i++){
            if(!visited[i] && i!=0){
                total++;
            }
        }

        cout<<total<<endl;

        for(int i=0;i<=n;i++){
            if(!visited[i] && i!=0){
                cout<<i<<" ";
            }
        }

    }

    cout<<endl;

}
