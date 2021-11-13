#include<bits/stdc++.h>
using namespace std;


int findLIS(int arr[],int n){

    int *lis;     // longest increasing subsequence
    int *lds;    //  longest decreasing subsequence
    lds = new int[n];
    lis = new int[n];
    for(int i=0;i<n;i++){
        lis[i]=1;
        lds[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
                lis[i] = lis[j]+1;
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }



    int ans=0;

    for(int i=0;i<n;i++){
        ans = max(ans,lis[i] + lds[i] - 1);
    }

    delete[] lis;
    delete[] lds;

    return ans;
}

int main(){

    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = findLIS(arr,n);

    cout<<ans<<endl;


    return 0;
}
