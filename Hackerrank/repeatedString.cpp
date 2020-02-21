#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long n,size,count=0;
    cin >> n; 
   
    long i=0,j=0;
    
    while(i<n) 
    {
        j=0;
        while(s[j]!='\0' && i<n)
        {
            if(s[j]=='a')
              count++;
            j++;
            i++;
        }  
    }
   
    cout<<count<<endl;
    
    return 0;
}

