#include<bits/stdc++.h>
using namespace std;


vector <int> adj[10];

int main(){

    int x, y, nodes, edges;
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges

    for(int i = 0;i < edges;++i){
        cin >> x >> y;
        adj[x].push_back(y);        //Insert y in adjacency list of x
     }


    for(int i = 1;i <= nodes;++i){

        cout << "Adjacency list of node " << i << ": ";

        for(int j = 0;j < adj[i].size();++j){
            if(j == adj[i].size() - 1)
                    cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
        }
    }


    return 0;
}

/*
    Sample Inputs


    Input file
4 // nodes
5 //edges
1 2 //showing edge from node 1 to node 2
2 4 //showing edge from node 2 to node 4
3 1 //showing edge from node 3 to node 1
3 4 //showing edge from node 3 to node 4
4 2 //showing edge from node 4 to node 2

4
5
1 2
2 4
3 1
3 4
4 2


*/

