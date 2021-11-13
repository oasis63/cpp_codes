#include <bits/stdc++.h>
using namespace std;

/* using binary search to find the number of elements strictly greater than
    or strictly smaller than the given key in an array
*/
// strictly greater than key
int  strictGreater(int a[],int n,int key){
    int l=0,r=n-1,mid;


    while(l<=r){
        mid=(l+r)/2;
      if(a[mid] <= key){
            if(a[mid+1] > key && (mid+1 < n)){
                break;
            }

            l=mid+1;

            if(l>=n){
               return 0;
            }
        }
        else{   // a[mid]  > key
            r=mid-1;
            if(r<0)
                return n;
        }
    }

    return (n-mid-1);

}

// strictly smaller than key
int  strictSmaller(int a[],int n,int key){
    int l=0,r=n-1,mid;


    while(l<=r){
        mid=(l+r)/2;
      if(a[mid] >= key){
            if(a[mid-1] < key && (mid-1  >= 0) ){
                break;
            }

            r=mid-1;
        }
        else{   // a[mid]  < key
            l=mid+1;

            if(l>=n)
                return n;

        }
    }

    return mid;

}


int main(){
   int a[] = {1,4,8,10,11};
   cout<<strictGreater(a,5,5)<<endl;
   cout<<strictSmaller(a,5,8)<<endl;

}
