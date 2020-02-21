#include<bits/stdc++.h>
using namespace std;

long int binary_search(long int arr[],long int start,long int end,long int key){
    long int mid;

    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

long int bin_greater(long int arr[],long int start,long int end,long int key){
    long int mid;

    while(start<=end){
        mid = start + (end-start)/2;
        
        if(arr[mid] > key){
            if((mid-1)>=0 && arr[mid-1] < key)
                return mid;
            end = mid-1;
        }else if(arr[mid] < key){
            start = mid+1;
        }
    }
    return -1;
}

pair<long int,long int> solve(long int arr[],long int n,long int sum){

    long int cumm[n];
    cumm[0] = arr[0];

    pair<long int,long int> p(-1,-1);

    for(long int i=1;i<n;i++)
        cumm[i] = cumm[i-1] + arr[i];

   /* for(long int i=0;i<n;i++)
        cout<<cumm[i]<<" ";
    cout<<endl;*/

    long int bs = binary_search(cumm,0,n-1,sum);

    if(bs!=-1){
        p = make_pair(1,bs+1);
        return p;
    }else{
        bs = bin_greater(cumm,0,n-1,sum);

        for(long int i=bs;i<n;i++){
            long int idx = binary_search(cumm,0,i-1,cumm[i]-sum);

            if(idx != -1){
                p = make_pair(idx+2,i+1);
                break;
            }
        }
    }

    return p;
}

int main(){
    
    long int tc;
    cin>>tc;
    
    while(tc--){
        long int n,sum;
        cin>>n>>sum;
        long int arr[n];
        for(long int i=0;i<n;i++)
            cin>>arr[i];
        
        pair<long int,long int> ap = solve(arr,n,sum);
        
        if(ap.first == -1)
            cout<<-1<<endl;
        else
            cout<<ap.first<<" "<<ap.second<<endl;
    }

    return 0;
}