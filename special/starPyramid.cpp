#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=3;

    for(int r=0;r<n;r++){
        for(int s=0;s<(n-r)-1;s++)
            cout<<" ";
        for(int i=0;i<=r;i++)
            cout<<"*";
        for(int i=0;i<r;i++)
            cout<<"*";
        cout<<endl;
    }

}
