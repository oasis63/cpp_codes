#include <bits/stdc++.h>
using namespace std;


int main()
{
	int k;
    string str;
    cin>>k;
    cin>>str;

    int len= str.length();

    int count =0;

    for (int i=0;i<len;i++)
    {
        set<int>s;  // repetititon is not allowed in set
        for(int j=i;j<len;j++)
        {
            s.insert(str[j]);

            if(s.size() == k )
            {
                count ++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}
