#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1; // undirected
}

// // Function to display the Adjacency Matrix
void displayMatrix(vector<vector<int>> &mat) {
    int V = mat.size();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {

    int v = 4;
    vector<vector<int>> mat(v, vector<int>(v, 0));

    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Alternatively we can also create using below
       code if we know all edges in advacem

     vector<vector<int>> mat = {{ 0, 1, 0, 0 },
                               { 1, 0, 1, 0 },
                               { 0, 1, 0, 1 },
                               { 0, 0, 1, 0 } }; */

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}

/*

Action	             Adjacency Matrix	Adjacency List
Adding Edge	             O(1)	          O(1)
Removing an edge	     O(1)	          O(N)
Initializing	         O(N*N)	          O(N)


*/
