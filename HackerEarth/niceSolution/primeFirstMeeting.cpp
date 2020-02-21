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


    int n,a;cin>>n;

    int mn=INT_MAX,mx=INT_MIN,get=0;

    for(int i=0;i<n;i++){
        cin>>a;
        if(primeArray[a]){
            mn=min(mn,a);
            mx=max(mx,a);
            get=1;

        }

    }

    if(get)
        cout<<abs(mx-mn)<<endl;
    else
        cout<<-1<<endl;



}
