#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int findMinXor(vector<int> &A) {

    int n = A.size();
    
    sort(A.begin(),A.end());
    int mn = INT_MAX;

    for(int i=0;i<n-1;i++){
        int t = A[i]^A[i+1];
        if(t < mn)
            mn = t;
    }

    return mn;
}

int main(){
    
    vector<int> vect{0,2,5,7};    
        
    cout<<findMinXor(vect)<<endl;

    return 0;
}