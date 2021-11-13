#include<bits/stdc++.h>
using namespace std;

string gcdStr(int a,int b){
    string div="";
    if(a%b==0){
        // a followed by a-1 zeros
        div+="1";
        for(int i=0;i<a-1;i++){
            div += "0";
        }
    }else{
        //first a characters from S(gcdStr(a,b))
        div += gcdStr(b,a%b).substr(0,a);

    }
    return div;
}


int main(){

    string binStr = gcdStr(5,2);
    cout<<binStr<<endl;
    bitset<32> bitSet(binStr);
    cout<<bitSet.to_ulong()<<endl;
}
