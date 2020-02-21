#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long int

/*

For a positive integer n let's define a function f:

f(n) =  - 1 + 2 - 3 + .. + pow((- 1),n)n

*/

int main(){

    fast;

    ll n;cin>>n;
    
    if(n%2==0){
        cout<<(n/2)<<endl;
    }else{
        cout<<-(n+1)/2<<endl;
    }



    return 0;
}

/*

input   output
1       -1
2       1
3       -2
4       2
5       -3
6       3
7       -4
8       4
....    ...
.       .
.       .
.       .

*/