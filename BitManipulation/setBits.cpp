#include<bits/stdc++.h>
using namespace std;

int setBits(int );

int solve(int n){
    int result = 0;

    for(int i=1;i<=n;i++){
        result += setBits(i);
    }

    return result;
}

int setBits(int n){

    if(n<=0)
        return 0;
    else
        return (n%2==0?0:1) + setBits(n/2);

}

int main(){

    cout<<solve(4)<<endl;
}
