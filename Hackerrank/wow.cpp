#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int sum(int x)
{
  int s=0,r;
  
  while(x!=0)
  {
    r=x%10;
    s+=r;
    x=x/10;
  }
 return s;
}

int func(int n)
{
   if(n<=9)
     return n;
   else
   return(func(sum(n)));
}

int main()
{
    int test,h;
    cin>>test;
    
    for(h=0;h<test;h++)
    {
    	int n,x,i,j,sum=0,r;
    	cin>>n;
    	
    	x=pow(n,3);
    	
    	cout<<func(x)<<endl;
    }
}

