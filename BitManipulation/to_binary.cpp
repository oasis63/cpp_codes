#include<bits/stdc++.h>
using namespace std;

int to_binary(int n){

    if(n==1)
        return 1;
    if(n%2==0)
        return 10*to_binary(n/2);
    else
        return 10*to_binary(n/2)+1;


}

int main(){
    
    for(int i=1;i<=10;i++){
        cout<<i<<"\t"<<to_binary(i)<<endl;
    }

    return 0;
}