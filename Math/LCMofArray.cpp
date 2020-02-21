#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int LCM(int arr[],int n){
    int result=arr[0];  // let it be the LCM

    for(int i=1;i<n;i++){
         result= ( ((arr[i]*result)) / (gcd(arr[i], result)) );     //  LCM(a,b)*HCF(a,b) = a*b;
    }

    return result;
}

int main()
{

    int n;cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
    cout<<"LCM of the given array : " << LCM(num,n)<<endl;


}
