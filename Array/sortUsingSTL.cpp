#include<bits/stdc++.h>
using namespace std;


void print(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int input[]={4,2,6,2,1,0};
    print(input,6);

//    for(int i=1;i<=6;i++){
//        sort(input,input+i);
//
//        print(input,6);
//    }

    cout<<"Sorting in increasing order " <<endl;

    sort(input,input+6);
    print(input,6);


    cout<<"Sorting in decreasing order " <<endl;

    sort(input,input+6,greater<int>());
    print(input,6);



}
