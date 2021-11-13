#include<bits/stdc++.h>
using namespace std;

int main(){

    int alpha[26];
    for(int i=0;i<26;i++){
        alpha[i]=0;
    }

    string str;
    cin>>str;

    for(int i=0;i<str.length();i++){
        alpha[str[i]-97] = 1;
    }

    int count=0;
    for(int i=0;i<26;i++){
        if(alpha[i])
            count++;
    }
//
//    for(int i=0;i<26;i++){
//        if(alpha[i]){
//            cout<<(char)(i+97)<<" "<<1<<endl;
//        }
//    }

    if(count%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }else{
        cout<<"IGNORE HIM!"<<endl;
    }
}

