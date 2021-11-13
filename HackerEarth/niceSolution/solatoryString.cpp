#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;cin>>n;

    string s;

    int len;

    set<char>mySet;

    while(n--){
        cin>>s;
        len = s.length();

        int hasher[26]={0};


        for(int i=0;i<len;i++){
            mySet.insert(s[i]);
            hasher[s[i]-97]++;
        }

        if(mySet.size() == len)
            cout<<-1<<endl;
        else{
            // contains at least 2 same characters

            int mx=INT_MIN;

            for(int i=0;i<len;i++){
                int count=0;
                int j=i+1;

                hasher[s[i]-97]--;

                while( hasher[s[i]-97] >= 1 && j<len){

                    //if(s[j]!=s[i])
                        count++;

                    if(s[j] == s[i])
                        hasher[s[i]-97]--;

                    j++;
                }

                count--;

                    if(count > mx)
                        mx=count;

            }

            cout<<mx<<endl;





        }

        mySet.clear();
    }
}
