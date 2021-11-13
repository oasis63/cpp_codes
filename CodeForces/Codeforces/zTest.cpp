#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,w;
    cin>>k>>n>>w;

    int totalCost = k*(w*(w+1)/2);

    if(totalCost > n)
        cout<<abs(n-totalCost)<<endl;
    else
        cout<<0<<endl;
}
