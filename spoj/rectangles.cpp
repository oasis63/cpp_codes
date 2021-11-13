// no of divisors
#include<bits/stdc++.h>
using namespace std;

int divisors(int n){
    int count=0;

    for(int i=1;i<=floor(sqrt(n));i++){
        if(n%i==0){
           count++;

        }
    }

    return count;
}

int main(){
    int n;

    cin>>n;
    int ans=0;

    for(int i=1;i<=n;i++){
        ans += divisors(i);
    }

    cout<<ans<<endl;
}
