/*

    Water Jug Problem 


    5 3  ----  4 
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){

    int tc,a,b,c;   
    cin>>tc;
    while(tc--){

        cin>>a>>b>>c;
        int mx=max(a,b);
        int mn = min(a,b);
        int g = gcd(a,b);

        if(c<=mx){
            if(c%g==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

}


/*
    2
    5 3 4
    3 6 4

    output:
        YES
        NO

*/