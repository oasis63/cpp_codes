#include<bits/stdc++.h>
using namespace std;

int main(){
    //code

    int tc;
    cin>>tc;

    while(tc--){
        
        int n , k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        sort(arr,arr+n);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > k)
                break;
            k -= arr[i];
            ans++;
        }

        cout<<ans<<endl;

    }
    
    
    return 0;
}