#include<bits/stdc++.h>
using namespace std;

// remove adjacent duplicates

int main(){

    string str = "acaaabbbacdddd";
    string ans = "";

    int len = str.length();

    // O(n^2)

    if(str[0] != str[1])
        ans += str[0];

    for(int i=1;i<len;i++){
        if((i-1) >= 0 && str[i] != str[i-1] &&  str[i] != str[i+1] && (i+1) < len){
            ans += str[i];
        }
    }

    if(str[len-1] != str[len-2])
        ans += str[len-1];

    cout<<ans<<endl;
}
