#include<bits/stdc++.h>
using namespace std;

// cypher application

char smlChar(char c,int k){

    int t = (c-'a' + k)%26;

    return (t+'a');
}

char cplChar(char c,int k){

    int t = (c-'A' + k)%26;

    return (t+'A');
}

char  number(char num,int k){

    int t = (num-'0'+k)%10;

    return (t+'0');
}

int main(){

//    cout<<smlChar('a',4)<<endl;
//    cout<<cplChar('Y',4)<<endl;
//    cout<<number('6',4)<<endl;

    string s; cin>>s;
    int k;cin>>k;

    for(int i=0;i<s.length();i++){

        if(s[i]>='a' && s[i]<='z'){
            s[i] = smlChar(s[i],k);
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i] = cplChar(s[i],k);
        }

        else if(s[i]>='0' && s[i]<='9'){
            s[i] = number(s[i],k);
        }

    }


    cout<<s<<endl;


}
