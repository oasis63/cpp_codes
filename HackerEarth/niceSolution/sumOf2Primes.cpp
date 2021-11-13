#include <bits/stdc++.h>
using namespace std;

#define range 1000002

int primeArray[range];

void setPrime(){

    for(int i=0;i<range;i++)
        primeArray[i]=1;

    primeArray[0]=0;
    primeArray[1]=0;

    for(int i=2;i<range;i++){
        if(primeArray[i]){
            for(int j=2*i;j<range;j+=i){
                primeArray[j]=0;
            }
        }
    }
}

int main(){
    setPrime();

    int t,n,a,b;cin>>t;

    while(t--){

        cin>>n;


        int get=0;

        for(int i=2;i<range;i++){

            if(primeArray[i]){

                b=n-i;

                if(b<0)
                    break;

                if(primeArray[b] ){
                    //cout<<"\t"<<b<<"\t"<<i<<endl;
                    get=1;
                    break;
                }

            }

        }

        if(get)
            cout<<"Deepa"<<endl;
        else
            cout<<"Arjit"<<endl;
    }
}
