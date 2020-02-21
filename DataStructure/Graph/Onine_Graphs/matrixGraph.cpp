#include <bits/stdc++.h>
using namespace std;

// adjacency matrix
bool A[10][10];

void initialize(){

    for(int i = 0;i < 10;++i){
        for(int j = 0;j < 10;++j){
            A[i][j] = false;
        }
    }
}

int main(){

    int x, y, nodes, edges;
    initialize();       //Since there is no edge initially
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges

    for(int i = 0;i < edges;++i){
        cin >> x >> y;
        A[x][y] = true;     //Mark the edges from vertex x to vertex y
   }

   if(A[3][4] == true)
      cout << "There is an edge between 3 and 4" << endl;
  else
      cout << "There is no edge between 3 and 4" << endl;

  if(A[2][3] == true)
      cout << "There is an edge between 2 and 3"<<endl;
  else
      cout << "There is no edge between 2 and 3" << endl;



    cout<<"\n Adjacency Matrix for the given graph : \n "<<endl;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
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

