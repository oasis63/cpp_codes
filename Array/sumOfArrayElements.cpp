#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int n = 3;   
    int arr[] = {2,4,7};
    int brr[10];
    for(int i=0;i<10;i++){
        brr[i] = 0;
    }

    int flag = 0;
    int top = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<=flag;j++){
            top++;
            brr[top] = arr[i] + brr[j];
        }
        flag = top;
    } 

    for(int i=0;i<10;i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;

    return 0;
}