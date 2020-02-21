#include<bits/stdc++.h>
using namespace std;

/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
*/

int minimumInsertionsDP(string str){
    int n = str.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));

    int l,h;

    for(int i=1;i<n;i++){
        for(l=0, h = i ; h < n; l++,h++){
            dp[l][h] = (str[l] == str[h]) ? dp[l+1][h-1] : min(dp[l+1][h],dp[l][h-1])+1;
        }
    }

    return dp[0][n-1];
}


int main(){

    int tc;
    cin>>tc;

    string str;

    while(tc--){
        cin>>str;
        cout<<minimumInsertionsDP(str)<<endl;
    }

    return 0;
}
