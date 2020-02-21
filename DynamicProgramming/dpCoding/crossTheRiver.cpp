#include<bits/stdc++.h>
using namespace std;

/*
There are 5 floating stones on a river. A man wants to cross the river.
He can move either 1 or 2 steps at a time. Find the number of ways in
which he can cross the river?

Ans: 13
*/


// recursive solution

int solve(int n){

    if(n<0)
        return 0;
    if(n==0)
        return 1;
    return solve(n-1)+solve(n-2);

}

// dynamic solution
int countWaysDyn(int n){

    int counter[n+1];
    counter[0]=1;
    counter[1]=1;

    for(int i=2;i<=n;i++){
        counter[i]=counter[i-1]+counter[i-2];
    }

    return counter[n];
}



int main(){

    int n = 6;
    cout<<solve(n)<<endl;
    cout<<countWaysDyn(n)<<endl;
}
