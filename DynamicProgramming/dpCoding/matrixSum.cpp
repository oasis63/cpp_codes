/*
    You are given a N*M  matrix. You need to print the sum of all the numbers 
    in the rectangle which has (1,1) as the top left corner and (x,y)  as the bottom right corner.


*/


#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long int


int main(){

    fast;

    int n,m;
    cin>>n>>m;

    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    int dp[n+1][m+1];

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mat[i-1][j-1];
        }
    }


    /*cout<<"\n\n"<<endl;


    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/


    int q,x,y;cin>>q;

    while(q--){
        cin>>x>>y;
        cout<<dp[x][y]<<endl;
    }
}


/*
    Sample I/O

    3 3
    1 2 3
    4 5 6
    7 8 9
    2
    3 3
    2 3


    output :
        45
        21



*/