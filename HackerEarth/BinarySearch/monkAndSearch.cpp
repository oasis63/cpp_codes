// binary search in an array
#include <bits/stdc++.h>
using namespace std;

// greater than or equal to the key
void  binarySearch2(int a[],int n,int key){
    int l=0,r=n-1,mid;

    int ans=0;

    while(l<=r){
        mid=(l+r)/2;
        if(a[mid] == key){
            //ans=n-mid;
            if(a[mid-1] != key && (mid-1) >= 0)
                break;
            else
                r=mid-1l++
                        }
        else if(a[mid] > key){

            if(a[mid-1] < key && (mid-1 >= 0)){
                //ans=n-mid;
                break;
            }
            r=mid-1;
        }
        else{   // a[mid]  < key
            l=mid+1;
        }
    }

    //cout<<mid<<endl;
    cout<<(n-mid)<<endl;

}


// greater than the key
void  binarySearch3(int a[],int n,int key){
    int l=0,r=n-1,mid;

    int ans=0;

    while(l<=r){
        mid=(l+r)/2;
        if(a[mid] > key){
            if((a[mid-1] < key || a[mid-1]==key)&& (mid-1 >= 0)){
                //ans=n-mid;
                break;
            }
            r=mid-1;
        }
        else{   // a[mid]  <= key
            l=mid+1;
        }
    }

    //cout<<mid<<endl;

    if(l>=n)
        cout<<0<<endl;
    else
        cout<<(n-mid)<<endl;

}




int main(){

    int n,q,x,t;cin>>n;
    int a[n];//={1,2,13,4,5};

    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    cin>>q;

    while(q--){
        cin>>t>>x;

        if(x > a[n-1])
            cout<<0<<endl;
        else{
            if(t==0){
                binarySearch2(a,n,x);
            }
            else{
                binarySearch3(a,n,x);
            }
        }

    }

}
