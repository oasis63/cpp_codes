#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while( t-- )
    {
        int size;
        cin>>size;

        string s;
        cin>>s;

        // char s2[size];
        // int index = 0;

        for(int i=0;i<size-1;i++)
        {
            for(int j=i;j<size-1;j++)
            {
                if( (j+1)<size)
                {
                    char temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;

                    // s2[index] = s[index];
                    // index++;
                    j++;
                }
            }
        }

        // s2[index] = '\0';

        // cout<<s2<<endl;
        cout<<s<<endl;
    }
}