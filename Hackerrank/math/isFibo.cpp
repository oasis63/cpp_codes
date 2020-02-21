#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll fiboArr[50]={0};   //  50 elements are under 10 digits

ll fibo(ll n){

    if(fiboArr[n] == 0){
        if(n<=1)
            fiboArr[n]=n;
        else
            fiboArr[n] = fibo(n-1) + fibo(n-2);
    }
    return fiboArr[n];
}


int main(){

    for(int i=0;i<50;i++){
        fibo(i);
    }


    ll tc,n;
    cin>>tc;

    while(tc--){
        cin>>n;

        int beg = 0,mid;
        int end = 49;
        bool found = false;

        while(beg<=end){
            mid = (beg+end)/2;
            if(fiboArr[mid]==n){
                found=true;
                break;
            }

            if(fiboArr[mid] > n){
                end=mid-1;
            }else if(fiboArr[mid] < n){
                beg=mid+1;
            }
        }

        if(found){
            cout<<"IsFibo"<<endl;
        }else{
            cout<<"IsNotFibo"<<endl;
        }
    }


}
