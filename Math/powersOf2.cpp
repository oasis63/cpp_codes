#include<bits/stdc++.h>
using namespace std;

int checkpower2(int n){

    while(n%2==0){
        n=n/2;
    }

    return n==1?1:0;
}

int main(){

    int n,temp;cin>>n;
    int count=0;
    while(n--){
        cin>>temp;
        count += checkpower2(temp);
    }
    cout<<count<<endl;
}
