#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
  int a,b,c;
  printf("\nEnter two numbers\n");
  cin>>a>>b;
  
  c=gcd(a,b);
  
  printf("%d\n",c);
}

