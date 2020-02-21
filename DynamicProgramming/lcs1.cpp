#include <bits/stdc++.h>
using namespace std;

/*
    Longest Common Subsequence 
*/


int lcs(string str1,string str2){

    int len1 = str1.length();
    int len2 = str2.length();

    int dp[len1+1][len2+1];

    for(int i=0;i<=len1;i++)
        dp[i][0]=0;
    for(int j=0;j<=len2;j++)
        dp[0][j]=0;


    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];
}


int main(){

   cout<<lcs("ABCDGH","AEDFHR")<<endl;

   cout<<lcs("AGGTAB","GXTXAYB")<<endl;
}
