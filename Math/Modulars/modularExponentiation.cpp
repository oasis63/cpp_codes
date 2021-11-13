#include <bits/stdc++.h>
using namespace std;

int binary(int n)
{

   int r,bin=0,j=1;
  
    while(n!=0)
    {
        r=n%2;
        bin = bin + r*j;    
        j*=10;
        n=n/2;
    }
    
 return bin;
}

int modularExpo(int a,int n,int m)
{
  int i,x=1,power=a%m,bin;
  
  bin=binary(n);
  
  while(bin!=0)
  {
    if(bin%10==1)
     x=(x*power)%m;
    power=(power*power)%m;
    bin=bin/10;
  }
  return x;
} 

int  main()
{
  int num,power,mod;

  mod = pow(10,9) + 7;

  cin>>num>>power;

  int ans = modularExpo(num,power,mod);

  ans = ans % mod;

  cout<<ans<<endl;
  
}
