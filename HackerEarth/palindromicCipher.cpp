#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while( t-- )
    {
        string str,s2;
        cin>>str;
        
        s2 = str;
        
        reverse(s2.begin(),s2.end());
        
        if( s2 == str)
        {
            cout<<"Palindrome"<<endl;
        }
        else
        {
            long long int prod=1;
            
            for(int i=0;i<str.length();i++)
            {
                int temp = str[i] - 96;
                prod *= temp;
            }
            
            cout<<prod<<endl;
        }
    }
}
