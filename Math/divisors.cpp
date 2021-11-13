#include <bits/stdc++.h>
using namespace std;

void divisors(int n)  //printing the divisors
{
  vector<int> v;

  for(int i=1;i<=sqrt(n);i++)
  {
    if( n%i == 0)
    {
      if(n/i == i)
      cout<<i<<" ";
      else
      {
        cout<<i<<" ";
        //cout<<n/i<<" ";
        v.push_back(n/i);
      }
    }
  }

 for(int i=v.size()-1;i>=0;i--)
  {
    cout<<v[i]<<" ";
  }

}

int main()
{
    int t;
    cin>>t;

    while( t-- )
    {
        int n;
        cin>>n;

       // cout<<divisors(n)<<endl;

        divisors(n);

        cout<<endl;
    }

    
}