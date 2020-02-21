#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll findTrailingZeros(ll n)
{	
	ll count = 0;

	for(ll i= 5; n/i >= 1 ; i *= 5)
	{
		count += n/i;
	}

	return count;
}

void solve(ll n){
    ll ans = 0,temp=0;

    while(n>0){
        temp = n/5;
        ans += temp;
        n=temp;
    }

    cout<<ans<<endl;
}

ll fact(ll n)
{
    if( n==0)
        return 1;
    else
        return(n*fact(n-1));
}

int main()
{
   while(1)
   {
         ll n;
         cin>>n;

        cout<<"Factorial of "<<n<<" is "<< fact(n)<<endl;
        cout<<"No of zeros at the end "<<findTrailingZeros(n)<<endl;
   }
}

