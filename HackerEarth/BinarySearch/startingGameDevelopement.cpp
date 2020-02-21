#include <bits/stdc++.h>
using namespace std;


// less than or equal to the key
int  binarySearch2(int a[],int n,int key){
    int l=0,r=n-1,mid;

    int ans=0;

    while(l<=r){
        mid=(l+r)/2;
      if(a[mid] <= key){

            if(a[mid+1] > key && (mid+1 < n)){
                //ans=n-mid;

                break;
            }
            l=mid+1;
        }
        else{   // a[mid]  > key
            r=mid-1;
        }
    }


    return mid+1;

}




int main(){

    int n,m,q;cin>>n>>m>>q;
    int a[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }


    while(q--){
        int mn = INT_MAX;
        int x,temp;
        for(int i=0;i<n;i++){
            cin>>x;
            temp = binarySearch2(a[i],m,x);

            if(temp < mn)
                mn=temp;
        }

        cout<<mn<<endl;
    }

}
