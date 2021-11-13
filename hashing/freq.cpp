#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int ar[n],h_table[n]={0};

 for(int i=0;i<n;i++) 
 {
    cin>>ar[i];
    h_table[ar[i]]++;
 }
 
     for(int i=0;i<n;i++)
     {  
         if(h_table[ar[i]]!=0)
       {
        cout<<ar[i]<<"  "<<h_table[ar[i]]<<endl;
        h_table[ar[i]]=0;
       } 
     }
 return 0;
}    
