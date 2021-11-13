#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc,n,k;
    cin>>tc;

    while(tc--){
        cin>>n>>k;
        int arr[n];
        int cnt[11];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cin>>arr[i];
            cnt[arr[i]]++;
        }

        int c = 0;
        for(int i=2;i<=10;i++){
            c += cnt[i];
        }

        if(c<=k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}
