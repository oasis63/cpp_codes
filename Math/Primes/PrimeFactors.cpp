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

void primeFact(int n){
    int ans=0;

    int temp = n;

    int div;

    for(int i=2;i<=temp;i++){
        while(primeArray[i]==1 && (n%i==0)){
            //ans=ans*10+primeArray[i];
            cout<<i<<" ";
            n=n/i;
        }
    }

}

int main(){

    setPrime();
    cout<<"Enter a number to see its prime factorization "<<endl;
    int n,ans=0;
    cin>>n;
    primeFact(n);




}
