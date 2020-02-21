// Program to find last two digits of n-th
// Fibonacci number

// This will work for large inputs also. like .. 1000000089

//after 300-th Fibonacci number last two digits starts repeating.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void precompute(ll fibo[])
{
    fibo[0] = 0;
    fibo[1] = 1;

    for (ll i = 2; i < 300; i++)
        fibo[i] = (fibo[i-1] + fibo[i-2])%100;
}


int findLastDigit(ll fibo[], int n)
{
    return fibo[n%300];
}

int main ()
{

    ll fibo[300] = {0};
    precompute(fibo);

    ll n = 1;
    cout << findLastDigit(fibo, n) << endl;
    n = 61;
    cout << findLastDigit(fibo, n) << endl;
    n = 7;
    cout << findLastDigit(fibo, n) << endl;
    n = 67;
    cout << findLastDigit(fibo, n) << endl;
    n=1000000067;
    //cout<<n%300<<endl;    // 167
    cout<<findLastDigit(fibo,n)<<endl;
    n=167;
    cout<<findLastDigit(fibo,n)<<endl;

    return 0;
}
