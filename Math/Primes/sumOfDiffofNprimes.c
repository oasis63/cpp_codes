//sum of differences of n prime numbers
#include<iostream>
#include<cmath>
using namespace std;

int prime(int n)
{
  int s,i;
  s=sqrt(n);
  
  for(i=2;i<=s;i++)
  {
    if(n%i==0)
     return 0;
  }
  return 1;
}
int main()
{
  int i=0,n,c=2,sum=0;
  cin>>n;
  
  int p[n],d[n];
  
  while(i<n)
  {
    if(prime(c))
    {
      
      p[i]=c;
      i++;
    }
    c++;
  }
  
  for(i=0;i<n;i++)
  cout<<p[i]<<endl;
  
  for(i=0;i<n;i++)
  {
    if(i+1 < n)
    {
      d[i]=p[i+1]-p[i];
    }
  }
  
  for(n=0;n<i-1;n++)
  cout<<d[n]<<" ";
  
  sum=0;
  
  for(n=0;n<i-1;n++)
   sum+=d[n];
   
   cout<<endl<<sum<<endl;
}
    
