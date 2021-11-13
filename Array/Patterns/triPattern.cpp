#include <bits/stdc++.h>
using namespace std;

void printMat(int n){

    int k = n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<k;
        }
        cout<<endl;
        k++;
    }

    for(int i=0;i<=n;i++){
        cout<<k;
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<k;
    }

    k--;
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<=(n-i-1);j++){
            cout<<k;
        }
        cout<<endl;
        k--;
    }
}


int main(){
    int n = 3;
   printMat(n);

}

/*
    intput :
        n = 3

    output :

        3
        44
        555
        6666
        6666
        555
        44
        3


*/
