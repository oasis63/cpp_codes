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


 int rangeBitwiseAnd(int m, int n) {
    int ans = 0;

    while(m && n){

        int msb1 = msbPos(m);
        int msb2 = msbPos(n);

        // If positions are not same, return 
        if(msb1 != msb2)
            break;

        int msb_val = (1<<msb1);

        ans += msb_val;

        m -= msb_val;
        n -= msb_val;
    }
    

    return ans;
}

// to find bit-wise & of all 
// numbers from x to y. 

int andOperator(int a, int b){ 
    while(a < b){ 
        // -b is the 2's complement of b when do bitwise or with b  
        //we get LSB and we subtract that from b 
        b -= (b & -b); 
    } 
    return b; 
} 

int main(){
    
    cout<<rangeBitwiseAnd(5,7)<<endl;  

    cout<<andOperator(5,7)<<endl;

    return 0;
}