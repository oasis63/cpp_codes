#include<bits/stdc++.h>
using namespace std;


int rec(int n,int k){
    if(n==1)
        return 1;
    else
        return (rec(n-1,k)+k-1) % n+1;
}

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        cout<<rec(n,k)<<endl;
    }

}
