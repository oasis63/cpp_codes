#include <bits/stdc++.h>
using namespace std;

// Print the Fibonacci Series in Reverse Order

int main(){


    int n = 10;

    int a=0,b=1;

    int arr[10];

    for(int i=0;i<n;i++){
        cout<<a<<" ";
        arr[i] = a;
        a=a+b;
        b=a-b;

    }

    cout<<"\nReverse Order "<<endl;

    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }

}
