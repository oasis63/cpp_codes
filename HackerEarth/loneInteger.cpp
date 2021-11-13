#include <bits/stdc++.h>
using namespace std;

#define ll  long long



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t,n;
    cin>>t;

    ll temp;

    while(t--){
        cin>>n;
        ll sum = 0;

        while(n--){
            cin>>temp;
            sum ^= temp;
        }

        if(sum==0){
            cout<<-1<<endl;
        }else{
            cout<<sum<<endl;
        }

    }

}
