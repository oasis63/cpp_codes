#include<bits/stdc++.h>
using namespace std;

/*

for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

*/


int main(){

    int tc;
    cin>>tc;

    while(tc--){

		int r;
		cin>>r;
		int mat[r][r]={0};

		for(int i=0;i<r;i++){
			for(int j=0;j<r;j++){
				mat[i][j]=0;
			}
		}

		for(int i=0;i<r;i++){
			for(int j=0;j<=i;j++){
				cin>>mat[i][j];
			}
		}


        for(int i=r-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                mat[i][j] += max(mat[i+1][j+1],mat[i+1][j]);
            }
        }

        cout<<mat[0][0]<<endl;


    }



}
