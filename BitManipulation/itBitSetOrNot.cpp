#include<bits/stdc++.h>
using namespace std;

// ith bit is set or not

bool isetCheck(int n,int i){

    //(1<<i) has ith bit set

    if((n&(1<<i)))  // bit manipulation
        return true;
    return false;
}

// driver method

int main(){
    cout<<"Enter a number and position in its binary form"<<endl;
    cout<<"to check it contains 1 or not "<<endl;
    int n,i;cin>>n>>i;

    cout<<isetCheck(n,i)<<endl;

}
