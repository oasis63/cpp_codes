#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int i,l,m,n,j;
    
    char str[1000];
    
    cin>>str;
    
    int sm=65,cap=97;
   
    int count[26]={0};
    
    for(i=0;str[i]!='\0';i++)
    {
        for(cap=65,sm=97;cap<=90,sm<=122;cap++,sm++)
        {
            if(str[i]==sm || str[i]==cap)
            {
              j=cap-65;
              count[j]++;    
            }
        }
        
    }
    
    int found=1;
    for(i=0;i<26;i++)
    {
        if(count[i]==0)
        {
           found=0;
        }
     }
   if(found)
   {
       cout<<"pangram\n";
   }
   else
     cout<<"not pangram";
    return 0;
}

