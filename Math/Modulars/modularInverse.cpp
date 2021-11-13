#include <iostream>
using namespace std;

#define ll long long

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}



int modInverse2(int A, int M)  // when M is prime or not - prime
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}


ll modExpo(ll x,ll n,ll m){
    if(n==0)
        return 1;
    else if(n%2==0)  // even power
        return  modExpo((x*x)%m,n/2,m);
    else
        return (x*modExpo((x*x)%m,(n-1)/2,m))%m;
}

ll modInverse(ll n, ll m)  // use this method when m is prime
{
    return modExpo(n,m-2,m);    //x may be negative
}


int main()
{
    ll a,b,c,m;cin>>a>>b>>c>>m;

    ll num = modExpo(a,b,m);

    ll den = modInverse2(c,m);

    cout<<(num*den)%m<<endl;
}
