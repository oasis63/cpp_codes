#include<bits/stdc++.h>
using namespace std;

// #  -> backspace string character

 bool backspaceCompare(string s, string t) {
    
    int len1 = s.length();
    int len2 = t.length();
    int cnt = 0;
    string str1="";
    for(int i=len1-1;i>=0;i--){
        if(s[i]=='#'){
            cnt++;
        }else{
            if(cnt>0){
                s[i]='#';
                cnt--;
            }else{
                str1 += s[i];
            }
        }
    }

    // cout<<s<<endl;
    // cout<<str1<<endl;

    string str2="";
    cnt = 0;
    for(int i=len2-1;i>=0;i--){
        if(t[i]=='#'){
            cnt++;
        }else{
            if(cnt>0){
                t[i]='#';
                cnt--;
            }else{
                str2 += t[i];
            }
        }
    }


    cout<<str1<<endl;
    cout<<str2<<endl;


    return str1==str2;
}


int main(){
    
    string str1 = "a##c";
    string str2 = "#a#c";    

    cout<<backspaceCompare(str1,str2)<<endl;

    return 0;
}