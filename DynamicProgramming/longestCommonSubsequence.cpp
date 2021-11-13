// Longest Common Sequence in two Sequences

#include<bits/stdc++.h>
using namespace std;

int lcs(char *x,char *y,int m,int n){
    int t[m+1][n+1];   // subsequence length table

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 ||  j==0 ) // first row and first column set to 0
                t[i][j]=0;
            else if(x[i-1]==y[j-1])
                t[i][j]=t[i-1][j-1]+1;
            else
                t[i][j]=max(t[i-1][j] , t[i][j-1]);
        }
    }

    return t[m][n];
}

int main(){
    char *x="AGGTAB";
    char *y="GXTXAYB";

    cout<<lcs(x,y,strlen(x),strlen(y))<<endl;   // common subsequence is " GTAB"
}


/*3
6 6
ABCDGH
ACDGHR
3 2
ABC
AC
6 7
AGGTAB
GXTXAYB*/

