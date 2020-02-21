#include<bits/stdc++.h>
using namespace std;

//#define ll long long

 #define  max(a,b) (a>b?a:b)

 const int M=1e9+7;

// modular exponentiaion

int modularExpo(int x,int n,int M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExpo((x*x)%M,n/2,M);
    else
        return (x*modularExpo((x*x)%M,(n-1)/2,M))%M;
}

int modExpo(int x,int n,int M){
    int result = 1;

    while(n != 0){
        if(n%2==1)
            result = (result*x)%M;
        x=(x*x)%M;
        n=n/2;
    }

    return result;
}

int main(){
    cout<<modularExpo(3,10,M)<<endl;
    cout<<modExpo(3,10,M)<<endl;

}
