#include<bits/stdc++.h>
using namespace std;

int solve(string slots[],int n,int m){

    int maxClasses = INT_MIN;

    for(int j=0;j<m;j++){
         int count=0;
        for(int i=0;i<n;i++){
            if(slots[i][j]=='1'){
                count++;
            }
        }
        if(count>maxClasses)
            maxClasses = count;
    }

    return  maxClasses;
}

int main(){

    string slots[] = {"0101011",
                        "0011001",
                        "0110111"};
    int n = 3;
    int m = 7;
    cout<<solve(slots,n,m)<<endl;

    string slots2[] = {"0101010","1010101"};
    n=2;
    cout<<solve(slots2,n,m)<<endl;
}
