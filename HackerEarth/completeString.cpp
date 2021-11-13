#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while( t-- )
    {
        string s;
        cin>>s;
        
        int len = s.length();

        if( len < 26 )
        {
            cout<<"NO"<<endl;
        }
        
        else
        {
            sort(s.begin(),s.end());
            
            for(int i=0;i<s.length();i++)
            {
                int j=i+1;
                
                while( s[i]==s[j])
                {
                    s.erase(j,1);
                }
            }
            
            int len2 = s.length();

            cout<<s<<endl;
            
            if( len2 == 26)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        
        
    }
}