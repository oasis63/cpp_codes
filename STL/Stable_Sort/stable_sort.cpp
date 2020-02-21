#include <bits/stdc++.h>
using namespace std;


//lexigoraphically sort

int main()
{
    int t;cin>>t;

    while(t--){
        string s1;cin>>s1;

        stable_sort(s1.begin(),s1.end());

        cout<<s1<<endl;

    }
}
