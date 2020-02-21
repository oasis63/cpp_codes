#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

bool isSorted(ll arr[],ll n){

    for(ll i=1;i<n;i++){
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int main(){

    fast;

    ll tc;
    cin>>tc;

    while(tc--){

        ll n;
        cin>>n;

        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }

        if(isSorted(arr,n)){

            cout<<"YES"<<endl;

        }else{

            //  3 4 5 1 2

            ll firstElem = arr[0];
            ll i=0,j=0;

            for(i=1;i<n;i++){
                if(arr[i] >= arr[i-1])
                    continue;
                break;
            }

           // cout<<"i :- "<<i<<endl;

            ll secElem = arr[i];
            i++;

            for(;i<n;i++){
                if(arr[i] >= arr[i-1])
                    continue;
                break;
            }

           // cout<<"i :"<<i<<endl;

            if(i==n){
                ll lastElem = arr[i-1];

                if(lastElem<=firstElem)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;

            }else{
                cout<<"NO"<<endl;
            }

        }


    }


   return 0;
}
