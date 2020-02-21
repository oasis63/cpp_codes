#include<bits/stdc++.h>
using namespace std;



int solve(int a[],int n,int key){

    if(a[0] > key)
        return -1;
    else if(a[n-1] <= key)
        return n-1;

    int beg=0,end=n-1,mid;

    while( beg <= end){

        mid=beg + (end-beg)/2;

        if( a[mid] == key){
            return mid;
        }
        else if( a[mid]  < key){

            if((mid+1)<=n-1 && a[mid+1] > key){
                return mid;
            }

             beg=mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return -1;
}


int main() {

    
    int tc;
    cin>>tc;

    while(tc--){
        int n,x;cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,n,x)<<endl;
    }

    return 0;
}

/*

Input:
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19

Output:
-1
1
3

*/