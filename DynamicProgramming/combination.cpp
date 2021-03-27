/*
    Merge two linked lists, the order of the elements of each list doesn't change.
*/

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int binomialCoeff(int n, int k) 
{ 
    int C[k + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // nC0 is 1 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = (C[j] + C[j - 1])%mod; 
    } 
    return C[k]; 
} 

// Complete the solve function below.
int solve(int n, int m) {

    return binomialCoeff(n+m,n>m?m:n);
}

int main(){
    
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        cout<<solve(n,m)<<endl;
    }

    
    return 0;
}