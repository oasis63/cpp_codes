#include<bits/stdc++.h>
using namespace std;

string part(string str,int l,int r,int n){
    while(l>=0 && r < n && str[l] == str[r]){
        l--;
        r++;
    }
    return str.substr(l+1,r-l-1);
}

string longestPalindrome(string str){

    string longest = str.substr(0,1);

    int len = str.length();

    for(int i=1;i<len-1;i++){
        string s1 = part(str,i,i,len);
        if(s1.length() > longest.length())
            longest = s1;
        string s2 = part(str,i,i+1,len);
        if(s2.length() > longest.length())
            longest = s2;

    }

    return longest;
}


int main(){

    int tc;
    cin>>tc;

    string str;

    vector<int> vect;
    vect.

    while(tc--){
        cin>>str;
        cout<<longestPalindrome(str)<<endl;
    }

    return 0;
}
