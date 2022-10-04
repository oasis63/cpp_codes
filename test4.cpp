#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

string sanitizeStr(string s){
    string str = "";
    int n = s.length();
    char c;
    for(int i=0;i<n;i++){
        c = tolower(s[i]);
        if((c>='a' && c<='z') || (c>='0' && c<='9')){
            str.push_back(c);
        }
    }
    return str;
}

int main(){
    
    // string str = "abc 3fdfasd,refd red";
    string str = ".";
    string s1 = sanitizeStr(str);
    string rev(s1);
    reverse(rev.begin(),rev.end());

    cout<<s1 <<"  "<< rev << endl;

    if(s1 == rev) cout<<true<<endl;
    else cout<<false<<endl;

    return 0;
}