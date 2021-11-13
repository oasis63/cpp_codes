#include <bits/stdc++.h>
using namespace std;

/*
    This is not the Dynamic Program for LCS.
*/

int lcs(string str1,int m,string str2,int n){

    if(m==0 || n==0)
        return 0;
    if(str1[m-1] == str2[n-1])
        return 1+lcs(str1,m-1,str2,n-1);
     else
        return max(lcs(str1,m-1,str2,n),lcs(str1,m,str2,n-1));

}

int main(){

    string str1 = "ABCDGH";
    string str2 = "AEDFHR";

    int m = str1.length();
    int n = str2.length();

   cout<<lcs(str1,m,str2,n)<<endl;

}
