#include<bits/stdc++.h>
using namespace std;

bool fun(int a,int b){
    return a>b?true:false;
}

void printArr(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
   int n;cin>>n;
   int a[n];
   int total = 0;
   for(int i=0;i<n;i++){
    cin>>a[i];
    total += a[i];
   }

   sort(a,a+n,fun);

    printArr(a,n);

}
