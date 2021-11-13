#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l;
    cin>>l;
    
    string s;
    cin>>s;
    
    
    int minLen = l ;
    
    int maxLen = l ;

    int i=0;

    for(;i<l;i++)
    {
        int countW=0;
        int countV = 0;

        while( s[i] == 'v' || s[i] == 'w')
        {
            if( s[i] == 'w')
                countW ++;
            if( s[i] == 'v')
                countV++;
            i++;
        }

        minLen = minLen - (countV/2); // 2 v's merge to form a single w 
        maxLen = maxLen + countW;   // 1 w splits to form two v 
    }
    
    cout<<minLen<<" "<<maxLen<<endl;
    
    
}