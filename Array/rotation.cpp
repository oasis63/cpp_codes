#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,K;
    cin>>T;
    
    for(K=0;K<T;K++)
    {
     int n,r,i,j,p,temp;
     cin>>n>>r;
     
     int num[n];
     
     for(i=0;i<n;i++)
      cin>>num[i];
      
     for(j=0;j<r;j++)
     {
       temp=num[n-1];
       for(i=n-2;i>=0;i--)
       {
         num[i+1]=num[i];
       }
       num[0]=temp;
       
     }
     
     for(i=0;i<n;i++)
     cout<<num[i]<<" ";
     
    }


}
