#include<bits/stdc++.h>
using namespace std;

int powerSum(int x,int n,int num){
    cout<<"Executed"<<endl;
    if(pow(num,n) < x)
        return powerSum(x,n,num+1)+powerSum(x-pow(num,n),n,num+1);
    else if(pow(num,n)==x)
        return 1;
    else
        return 0;
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<powerSum(x,n,1)<<endl;
}
