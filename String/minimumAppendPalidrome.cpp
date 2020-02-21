/*

#insertion at the end of the string to make it palindrome 

Minimum number of Appends needed to make a string palindrome

*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

bool isPalindrome(string str){

    int n = str.length();

    int i=0,j=n-1;

    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int minimumAddEnd(string str){

    int n = str.length();
    int ans = 0;

    bool flag = false;

    while(str.length() > 0){

        if(isPalindrome(str)){
            flag = true;
            break;
        }else{  
            ans++;
            str = str.substr(1);  // remove the first element
        }
    }

    if(flag)
        return ans;

    return -1;

}


int minimumAppends(string s){
    if(isPalindrome(s))
        return 0;
    // removing the first character of string
    // by incrementing base address pointer
    // cout<<s<<endl;
    s = s.substr(1);

    return 1+minimumAppends(s);
}

int main(){
    
    string str = "ABC";

    cout<<minimumAppends(str)<<endl;
    cout<<minimumAddEnd(str)<<endl;

    string st2 = "AACECAAAA";

    cout<<minimumAppends(st2)<<endl;
    cout<<minimumAddEnd(st2)<<endl;



    return 0;
}