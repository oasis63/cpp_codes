#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main(){

    ull n,m,temp;
    cin>>n>>m;
    if(n==1 || m==1){
        if(n==1)
            temp=m;
        else
            temp=n;
        cout<<(--temp)<<endl;
    }else{
        temp = m-1;
        temp += (n-1)*m;
        cout<<temp<<endl;
    }


}
