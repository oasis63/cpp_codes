// sorting of a row of 2D vector 
#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    // Initializing 2D vector "vect" with 
    // values 
    vector< vector<int> > vect{{3, 5, 1}, 
                               {4, 8, 6}, 
                               {7, 2, 9}}; 
    // Number of rows; 
    int m = vect.size(); 
  
    // Number of columns (Assuming all rows 
    // are of same size).  We can have different 
    // sizes though (like Java). 
    int n = vect[0].size(); 
  
    // Displaying the 2D vector before sorting 
    cout << "The Matrix before sorting 1st row is:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
           cout << vect[i][j] << " "; 
        cout << endl; 
    } 
  
    // Use of "sort()" for sorting first row 
    sort(vect[0].begin(), vect[0].end()); 
  
    // Displaying the 2D vector after sorting 
    cout << "The Matrix after sorting 1st row is:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 
  
    return 0; 
} 