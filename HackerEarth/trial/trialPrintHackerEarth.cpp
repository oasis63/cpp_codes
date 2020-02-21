#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int small = 1000000;

    string s;
    cin>>s;
    
    int counter[200];

    for(int i=0;i<200;i++)
    {
        counter[i] = 0;
    }

    for(int i=0;s[i]!='\0';i++)
    {
        counter[s[i]] ++;
    }

    string s1 = "hackerearth";

    for(int i=0;s1[i]!='\0';i++)
    {
        if(s1[i]=='h' || s1[i]=='a' || s1[i]=='e' || s1[i]=='r')
        {
            int r = counter[s1[i]] / 2;

            if(r==0)
                break;
            else
            {
                if(r < small)
                    small = r;

            }
        }
        else if(s1[i]=='c' || s1[i]=='k' || s1[i]=='t')
        {
            int r = counter[s1[i]] / 2;

            if(r==0)
                break;
            else
            {
                if(r < small)
                    small = r;

            }
        }
    }

    cout<<small<<endl;


}