#include <bits/stdc++.h>
using namespace std;

#define range 1000002

int primeArray[range];

void setPrime(){

    for(int i=0;i<range;i++)
        primeArray[i]=1;

    primeArray[0]=0;
    primeArray[1]=0;

    for(int i=2;i<sqrt(range);i++){
        if(primeArray[i]){
            for(int j=i*i;j<range;j+=i){
                primeArray[j]=0;
            }
        }
    }
}

int main(){

    setPrime();
    int hasher[26]={0};
    int t;cin>>t;
    string s;

    while(t--){
        cin>>s;
        int len = s.length();


        for(int i=0;i<26;i++)
            hasher[i]=0;

        set<char>mSet;  // to take only distinc characters as input

        for(int i=0;i<len;i++){
            mSet.insert(s[i]);
            hasher[s[i]-97]++;
        }


        int dCount = mSet.size();

        if(primeArray[dCount]!=1)
            cout<<"NO"<<endl;
        else{
            int get=1;   // prime occrurrences

            for(int i=0;i<26;i++){
                if(hasher[i] && (primeArray[hasher[i]]==0)){
                    get=0;
                    break;
                }
            }

            if(get)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;


        }

    }

}
