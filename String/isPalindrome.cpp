#include <bits/stdc++.h>
using namespace std;

bool isPalindrome2(string s){

    string rev = s;
    reverse(rev.begin(),rev.end());
    if(rev==s)
        return true;
    else
        return false;

}

bool isPalindrome(string s){
    
    int i = 0;
    int j = s.length()-1;
    
    while(i<=j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    
    return true;
}

int main(){


    cout<<isPalindrome("ababa")<<endl;
    cout<<isPalindrome("abba")<<endl;
    cout<<isPalindrome("abcdef")<<endl;

}