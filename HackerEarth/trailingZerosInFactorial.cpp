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

ll fact(ll n)
{
    if( n==0)
        return 1;
    else
        return(n*fact(n-1));
}

int main()
{
   int t;
   cin>>t;

   while( t-- )
   {
        ll n,count=0;
        cin>>n;


        vector<ll>v;

        ll i=1;

        while(1)
        {
            ll noZeros = findTrailingZeros(i);

            if( noZeros == n)
            {
                count ++;
                v.push_back(i);
            }

            else if( noZeros > n)
            {
                break;
            }

            i++;

        }

        cout<<count<<endl;

        for (ll i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<" ";
        }

        cout<<endl;
   }
}

