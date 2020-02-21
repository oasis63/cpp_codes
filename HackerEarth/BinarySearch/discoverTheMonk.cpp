// binary search in an array
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int a[],int n,int key){
    int l=0,r=n-1,mid;
    bool get=false;

    while(l<=r){
        mid=(l+r)/2;
        if(key==a[mid]){
            get=true;
            break;
        }
        else if(key>a[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    return get;
}


int main(){

    int n,q,x;cin>>n>>q;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    while(q--){
        cin>>x;

        if(binarySearch(a,n,x))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
