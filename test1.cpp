#include<bits/stdc++.h>
#include<vector>
using namespace std;

int minDist(int N,int X[]){
    
    int result = -404;

    int sum = 0;    

    for(int i=0;i<N;i++){
        sum += X[i];
    }

    int avg = sum/N;

    cout<<avg<<endl;
    cout<<N<<endl;


    result = 0;

    for(int i=0;i<N;i++){
        result += abs(avg - X[i]);
    } 

    return result;
}

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

int 
modularExpo(int a,int n,int m)
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

long int modularExpo2(long int x,long int n,long int M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExpo2((x*x)%M,n/2,M);
    else
        return (x*modularExpo2((x*x)%M,(n-1)/2,M))%M;
}


int main(){

    cout<<pow(2,1603)<<endl;

    cout<<modularExpo(2,50,1)<<endl;


    cout<<modularExpo2(2,50,1)<<endl;


    // int ans = modularExpo(num,power,mod);

    return 0;
}