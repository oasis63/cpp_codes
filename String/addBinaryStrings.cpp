#include<bits/stdc++.h>
using namespace std;

string addBinary(string A, string B) {

    int n = A.length();
    int m = B.length();

    if(n<m)
        return addBinary(B,A);

    // n > m
    string ans = "";
    bool carry = false;
    int j = n-1;

    for(int i=m-1;i>=0;i--,j--){
        if(A[j] == '1' && B[i] == '1'){
            if(carry){
                ans += '1';
                carry = true;
            }else{
                carry = true;
                ans += '0';
            }
        }else if((A[j] == '0' && B[i] == '1') || (A[j] == '1' && B[i] == '0')){

            if(carry){
                ans += '0';
                carry = true;
            }else{
                carry = false;
                ans += '1';
            }
        }else{

            if(carry){
                ans += '1';
                carry = false;
            }else{
                ans += '0';
            }
        }
    }

    while(j>=0){
        if(A[j]=='1'){

            if(carry){
                ans += '0';
            }else{
                ans += '1';
            }
        }else{
            if(carry){
                ans += '1';
                carry=false;
            }else{
                ans += '0';
            }
        }
        j--;
    }

    if(carry)
        ans += '1';

//    cout<<ans<<endl;

    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){

    string A = "1000011011000000111100110";
    string B = "1010110111001101101000";

    cout<<addBinary(A,B)<<endl;
}
