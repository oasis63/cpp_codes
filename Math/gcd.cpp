#include<iostream>
using namespace std;

int naiveGCD(int a,int b){
    int m = min(a,b);

    for(int i=m;i>0;i--){
        if(a%i==0 && b%i==0)
            return i;
    }
}

int iterGCD(int a,int b){

    while(a!=0){
        int rem = b%a;
        b=a;
        a=rem;
    }

    return b;
}

int recurGCD(int a,int b){
    if(a==0)
        return b;
    else
        return recurGCD(b%a,a);
}



int main(){
    cout<<naiveGCD(18,27)<<endl;
    cout<<iterGCD(27,0)<<endl;
    cout<<iterGCD(27,18)<<endl;
    cout<<recurGCD(27,18)<<endl;

    return 0;
}
