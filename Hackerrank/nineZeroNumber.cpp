#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

ll to_binary(ll n){

    if(n==1)
        return 1;
    if(n%2==0)
        return 10*to_binary(n/2);
    else
        return 10*to_binary(n/2)+1;


}

int main(){
    
    int tc;
    cin>>tc;

    while(tc--){
        ll n,a=1,b=9;
        cin>>n;
        while(b%n!=0){
            a++;
            b=to_binary(a);
            b=b*9;
        }
        cout<<b<<endl;
    }

}