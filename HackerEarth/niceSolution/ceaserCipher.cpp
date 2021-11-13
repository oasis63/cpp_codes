#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;

    while(t--){
        string s1,s2;cin>>s1;
        cin>>s2;

        int len = s1.length();

        int k=0;

        for(k=0;k<=26;k++){
            if((s2[0]-65) == (s1[0]-65+k)%26)
                break;
        }

        //cout<<k<<endl;

        int get=1;

        for(int i=1;i<len;i++){
            if((s2[i]-65) != (s1[i]-65+k)%26){
                get=0;
                break;
            }
        }

        if(get)
            cout<<k<<endl;
        else
            cout<<-1<<endl;

    }
}
