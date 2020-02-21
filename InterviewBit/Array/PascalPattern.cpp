/*
Pascal Triangle Pattern

1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1 


*/


#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solve(int n) {

    vector<vector<int>>vect(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                vect[i].push_back(1);
            }else{
                vect[i].push_back(vect[i-1][j]+vect[i-1][j-1]);
            }
        }
    }

    return vect;
}


int main(){
    
    vector<vector<int>>vect =solve(5);

    for(int i=0;i<vect.size();i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}