// CPP program to create a 2D vector where  
// every row has  
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // size of row 
    int row = 5; 
    int colom[] = { 5, 3, 4, 2, 1 }; 
  
    // Create a vector of vector with size 
    // equal to row. 
    vector<vector<int> > vec(row);  
  
    for (int i = 0; i < row; i++) {
  
        // size of column 
        int col;  
        col = colom[i]; 
  
        // declare  the i-th row to size of column 
        vec[i] = vector<int>(col); 
        for (int j = 0; j < col; j++) 
            vec[i][j] = j + 1; 
    } 
  
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < vec[i].size(); j++) 
            cout << vec[i][j] << " "; 
        cout << endl; 
    } 
}