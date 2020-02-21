#include <bits/stdc++.h>
using namespace std;

#define range 1000002

int primeArray[range];

void setPrime(){

    for(int i=0;i<range;i++)
        primeArray[i]=1;

    primeArray[0]=0;
    primeArray[1]=0;

    for(int i=2;i<sqrt(range);i++){
        if(primeArray[i]){
            for(int j=i*i;j<range;j+=i){
                primeArray[j]=0;
            }
        }
    }
}

int main(){

    setPrime();

    int n;cin>>n;

    int mn = INT_MAX;

    int a=0 ,b=0;


    for(int i=2;i<n;i++){

        if(primeArray[i] && primeArray[n-i]){
            //cout<<i<<" "<<(n-i)<<endl;
            int d = n-2*i;

            if(d<mn && d>0){
                a=i;
                b=n-i;
                mn-d;
            }
            else if( d==mn && i<a){
                a=i;
                b=n-i;
            }
        }
    }

    if(a==0 && b==0)
        cout<<"Not Possible"<<endl;
    else
        cout<<a<<" "<<b<<endl;


}
