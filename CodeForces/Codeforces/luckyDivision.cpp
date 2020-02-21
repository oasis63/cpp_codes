#include<bits/stdc++.h>
using namespace std;

int isLuckyNumber(int n){
    while(n!=0){
        int r=n%10;
        //cout<<r<<endl;
        if(r!=4 && r!=7){
            return 0;
        }
        n=n/10;
    }
    return 1;
}

int main(){


    int n;cin>>n;
    if(isLuckyNumber(n)){
        cout<<"YES"<<endl;
    }else{
        int get=0;
        for(int i=4;i<=(n/2);i++){
            if(isLuckyNumber(i) && n%i==0){
                cout<<"YES"<<endl;
                get=1;
                break;
            }
        }

        if(!get)
            cout<<"NO"<<endl;
    }


}

