#include <bits/stdc++.h>
using namespace std;

// printing the sub array of an array

void printSubArr(int a[],int n){

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++)
                cout<<a[k]<<" ";
            cout<<endl;
        }
    }

}



int main(){
    int a[] = {1,2,3,4};
    printSubArr(a,4);
}
