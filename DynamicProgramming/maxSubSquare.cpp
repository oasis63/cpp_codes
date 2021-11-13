//Maximum size square sub-matrix with all 1s
#include<bits/stdc++.h>
using namespace std;

#define R 6
#define C 5

int min(int a,int b,int c){
    return min(a,min(b,c));
}

void printMaxSubSquare(int mat[R][C]){

    int dp[R][C];

    for(int i=0;i<R;i++){
        dp[i][0] = mat[i][0];
    }

    for(int j=0;j<C;j++){
        dp[0][j] = mat[0][j];
    }


    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){

            if(mat[i][j]==1){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            }else{
                dp[i][j] = 0;
            }
        }
    }

    int max_s=dp[0][0];
    int max_i=0;
    int max_j=0;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(dp[i][j] > max_s){
                max_s=dp[i][j];
                max_i=i;
                max_j=j;
            }
        }
    }


    for(int i=max_i;i>max_i-max_s;i--){
        for(int j=max_j;j>max_j-max_s;j--){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }



}

int main(){



    int mat[R][C] =  {
                        {0, 1, 1, 0, 1},
                        {1, 1, 0, 1, 0},
                        {0, 1, 1, 1, 0},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0}
                    };

  printMaxSubSquare(mat);

}

