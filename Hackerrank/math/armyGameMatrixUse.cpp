#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int mat[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=1;
        }
    }

    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]){
                mat[i][j]=0;
                if((j+1)<m){
                    mat[i][j+1]=0;
                }
                if((i+1)<n){
                    mat[i+1][j]=0;
                }
                if((j+1)<m && (i+1)<n){
                    mat[i+1][j+1]=0;
                }
                cnt++;
            }
        }
    }


    cout<<cnt<<endl;


}
