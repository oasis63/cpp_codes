#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// maximize array sum

ll findPivot(ll arr[],ll beg,ll end){

    ll left = beg;
    ll loc = left;
    ll right = end;
    ll get = 1;


    while(get){

        while(arr[loc] <= arr[right]  && loc!=right){
            right--;
        }

        if(loc == right){
            get=0;
           break;
        }else if(arr[loc] > arr[right]){
            ll temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }


        if(get){

            while(arr[left] <= arr[loc]  && loc!=left){
                left++;
            }

            if(loc==left){
                get=0;
                break;
            }else if(arr[loc] < arr[left]){
                ll temp = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp;
                loc=left;
            }
        }
    }

    return loc;
}

void quickSort(ll arr[],ll beg,ll end){

    ll pivot;

    if(beg < end){

        pivot = findPivot(arr,beg,end);
        quickSort(arr,beg,pivot-1);
        quickSort(arr,pivot+1,end);
    }
}

void prll(ll arr[],ll n){

    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    ll tc;cin>>tc;
    
    while(tc--){
        
        ll n;cin>>n;
        ll arr[n-1];
        
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
    
        quickSort(arr,0,n-1);
    
        ll sum[n];
        sum[0] = arr[0];
    
        for(ll i=1;i<n;i++){
            sum[i] = sum[i-1] + arr[i];
        }
    
        //prll(arr,n);
        //prll(sum,n);
    
        ll ans = 0;
    
        ans = arr[0]*n;
    
        for(ll i=1;i<n;i++){
    
            ll negSum = -1*sum[i-1];
            ll posSum = arr[i]*(n-i);
    
            ll totSum = negSum + posSum;
    
            
            if(totSum > ans)
                ans = totSum;
        }
    
        cout<<ans<<endl;
    }
    
    return 0;
    
}