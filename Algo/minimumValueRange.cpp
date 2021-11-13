#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {-3,2,1,-4};
    int n = 4;

    int dp[n][n];

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }

    int minValue = 0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            if(i==j)
                minValue = arr[j];
            else if(minValue > arr[j]){
                minValue = arr[j];
            }
            dp[i][j] = minValue;
        }
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }

}
