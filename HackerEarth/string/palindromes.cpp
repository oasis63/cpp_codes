#include <bits/stdc++.h>
using namespace std;


// if all the characters are same
// then it will always be palindrome

bool sameCharacters(string str){
    int n = str.length();
    for(int i=1;i<n;i++){
        if(str[i]!=str[0])
            return false;
    }

    return true;
}


int solve(string s){

    int n = s.length();
    int i = 0;
    int j = n-1;

    if(n==1 || sameCharacters(s))
        return 0;



    while(i<=j){
        if(s[i]!=s[j])
            return (j-i+1);
        else if(s[i]!=s[j-1] && j>0)
            j--;
        else if(s[i+1]!=s[j] && i<n-1){
            i++;
        }
    }

}


int main()
{
    string s,sub;cin>>s;
    cout<<solve(s)<<endl;
}
