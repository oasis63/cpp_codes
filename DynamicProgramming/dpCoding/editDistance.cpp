/*  Edit Distance
    Minimum number of operations or edits required to convert
    string1 to string2

    //operations are delete,modify,insert

*/

#include<bits/stdc++.h>
using namespace std;

int min(int a,int b,int c){
    return min(a,min(b,c));
}


int editDist(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    int dist[m+1][n+1];

    memset(dist,0,sizeof(dist));


    for(int i=0;i<=m;i++){
        dist[i][0]=i;
    }

    for(int j=0;j<=n;j++){
        dist[0][j]=j;       
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(s1[i-1]==s2[j-1])
                dist[i][j]=dist[i-1][j-1];
            else
                dist[i][j]=1+min(dist[i][j-1],dist[i-1][j],dist[i-1][j-1]);
        }
    }

    return dist[m][n];
}

int main(){
    cout<<editDist("sunday","saturday")<<endl;
    cout<<editDist("cat","cut")<<endl;
}

