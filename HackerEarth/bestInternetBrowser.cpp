#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    string sub;

    cin>>str;

    int len = str.length();

    int subLen = len - 8;

    sub = str.substr(4,subLen);

    cout<<"Length : "<<len<<endl;

    cout<<sub<<endl;

    int consonant = 0;

    for(int i=0;i<subLen;i++)
    {
        if( sub[i] != 'a' && sub[i] != 'e' && sub[i] != 'i' && sub[i] != 'o' && sub[i] != 'u')
            consonant ++;
    }

    cout<<consonant<<endl;

    printf("%d/%d\n",consonant+4,len );
}