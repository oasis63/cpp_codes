#include<bits/stdc++.h>
using namespace std;

void minimizeWithKSwaps(int n,int k,int arr[]){

    int j = 0;
    for(int i=0;i<n;i++){

        int idx = i;

        for(j=i+1;j<=(i+k) && j<n;j++){
            if(arr[j] > arr[idx]){   // find the largest element
                idx=j;
            }
        }

        if(idx!=i){

            for(int j=idx;j>i;j--){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1] = temp;
                k--;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;

}

int main(){

    int tc;cin>>tc;

    while(tc--){
        int n,k;
        cin>>n>>k;

        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        minimizeWithKSwaps(n,k,arr);
    }
}

/*
    Sample Input

    3
    5 3
    3 5 1 2 1
    5 3
    3 1 2 1 2
    3 2
    2 3 4


    Sample Output

    53211
    32211
    423



*/
