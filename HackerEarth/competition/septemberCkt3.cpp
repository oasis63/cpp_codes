#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,m;cin>>n>>k>>m;

    int pay[m][n] = {0};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>pay[i][j];
        }
    }

    int myPay[n];

    for(int i=0;i<n;i++)
        cin>>myPay[i];

    int maxProfit = 0;
    int total = 0;

    int index=0;

    for(int i=0;i<(n-k);i++){

        for(int l=0;l<m;l++){

            int rowMin=INT_MAX;

            for(int j=i;j<(i+k);j++){
                if(pay[l][j] < rowMin)
                    rowMin = pay[l][j];
            }

            total += rowMin;
        }

        for(int my=i;my<(i+k);my++)
            total -= myPay[my];

        if(total > maxProfit){
            maxProfit = total;
            index = i;
        }

    }

    for(int i=0;i<k;i++){
        cout<<(index+i+1)<<" ";
    }

    cout<<endl;

}
