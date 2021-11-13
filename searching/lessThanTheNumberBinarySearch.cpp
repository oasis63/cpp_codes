#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


int binarySearch(int arr[],int n,int elem){

    int beg = 0,end = n-1,mid;

    if(elem < arr[0])
        return 0;
    else if(elem >= arr[n-1])
        return n;

    while(beg<=end){

        mid = (beg+end)/2;

        if(arr[mid] == elem){

            if(arr[mid+1] == elem)
                beg = mid+1;
            else
                return mid+1;

        }else if(elem > arr[mid]){

            beg = mid + 1;

        }else{// elem < arr[mid]

            if(arr[mid-1] <= elem)
                return mid;
            else
                end = mid - 1;

        }
    }

    return 0;
}


int main(){
    
    int n;// = 5;
    cin>>n;
    int arr[n];// = {3,10,8,6,11};

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    int q,elem;
    cin>>q;

    while(q--){
        cin>>elem;
        cout<<binarySearch(arr,n,elem)<<endl;
    }

    return 0;
}