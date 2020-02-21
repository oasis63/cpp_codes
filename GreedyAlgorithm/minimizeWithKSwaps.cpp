#include<bits/stdc++.h>
using namespace std;

/*

swapping should be done between adjacent elements only

*/


void minimizeWithKSwaps(int arr[],int n,int k){

    for(int i=0;i<n;i++){
        int pos = i;

        for(int j=i+1;j<n && j<=(i+k);j++){
            if(arr[j] < arr[pos]){
                pos=j;
            }
        }

        if(pos!=i){
            for(int j=pos;j>i;j--){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1] = temp;
                k--;
            }
        }
    }


}

int main(){

    int arr[] = {7, 6, 9, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;

    minimizeWithKSwaps(arr, n, k);

    //Print the final Array
    for (int i=0; i<n; ++i)
        cout << arr[i] <<" ";
}
