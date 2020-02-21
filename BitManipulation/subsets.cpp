#include<bits/stdc++.h>
using namespace std;

// generating all the subset in of a set

bool iBitSet(int n,int i){

    if((n & (1<<i)))
        return true;
    return false;
}


void subsets(int a[],int n){

    // number of subsets == pow(2,n)

    for(int i=0;i< (1<<n);i++){  // (1<<n) == pow(2,n)
        for(int j=0;j<n;j++){

            if(iBitSet(i,j)){  // jth bit is set in i
                cout<<a[j]<<" ";
            }
        }

        cout<<endl;
    }
}

int main(){

    int input[] = {1,2,3};
    int n=3;

    subsets(input,n);
}
