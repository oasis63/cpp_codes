#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<vector<int>> mat {
        {1,0,0,0,1},
        {1,1,0,1,1},
        {1,0,1,0,1},
        {1,1,0,1,1},
        {1,0,0,0,1}
    };


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i+j == 4  || abs(i-j) == 0 )
             cout<<mat[i][j]<<" ";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


}
