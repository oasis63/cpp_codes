#include <bits/stdc++.h> 
using namespace std; 
#define MAX 100 
  
// Find the binomial coefficient up to nth  
// term 
int binomialCoeff(int n, int k) 
{ 
    int C[k + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // nC0 is 1 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j - 1]; 
    } 
    return C[k]; 
} 
  

int sumOfproduct(int n) 
{ 
    return binomialCoeff(2 * n, n - 1); 
} 
  
// Driven Program 
int main() 
{ 
    int n = 3; 
  
    cout << sumOfproduct(n) << endl; 
    return 0; 
} 