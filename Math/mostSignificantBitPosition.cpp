#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

// most significant bit position of a number

int msbPos(int n) {

    int msb_p = -1; 
    while (n){ 
        n = n>>1; 
        msb_p++; 
    } 
    return msb_p; 
} 


int main(){
    
    cout<<"Most significant bit position "<<endl; 
    
    for(int i=0;i<20;i++){
        cout<<i<<"\t"<<msbPos(i)<<endl;
    }


    return 0;
}