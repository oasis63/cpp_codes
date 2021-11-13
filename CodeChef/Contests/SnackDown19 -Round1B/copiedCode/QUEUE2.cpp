#include <bits/stdc++.h>
using namespace std;
int main() {
 
   long long int t;
    
    long long int n,m,k,l,i,j;
    cin>>t;
    while(t--){
 
     long long int max=1000000000000000;
     cin>>n>>m>>k>>l;

     long long int a[n],sum=0,x=0,b;

     b=m*l;

     for(i=0;i<n;i++)
     {
         cin>>a[i];
     }

     sort(a, a+n);

     for(j=0;j<n;j++)
     {
         
         
         sum=b+((j+1)*l)-a[j];
         if(sum<max)
         {
             max=sum;
         }
         
     }

     x=b+((n)*l)-k+l;

     {
         if(x<max)
         {
             max=x;
         }
     }

     cout<<max<<"\n";
     
        
        
        
    }


    return 0;
}