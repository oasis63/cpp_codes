#include <bits/stdc++.h>
using namespace std;

// sum of square of two number

int sumSquare(int n){

    for(int i=0;i<=sqrt(n);i++){
        for(int j=0;j<=sqrt(n);j++){
            if(i*i + j*j == n){
                cout<<i<<" "<<j<<endl;
                return 1;
            }
        }
    }
    return 0;
}

int main(){

  sumSquare(36);

}
