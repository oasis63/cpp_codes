#include <bits/stdc++.h>
using namespace std;


void trianglePatternPrint(int n){

    int k=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
                cout<<k;
            if(j!=i)
                cout<<"*";
            k++;
        }
        cout<<endl;
    }

    k = k-n;

    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<k;
            if(j!=i)
                cout<<"*";
            k++;
        }
        cout<<endl;
        k=k-(i*2)+1;
    }

}

int main(){

    trianglePatternPrint(4);

    cout<<endl;

    trianglePatternPrint(6);

}
