#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

string addBin(string bin){
    int n = bin.length();
    int i = n-1;
    if(bin[i] == '0'){
        bin[i] = '1';
        return bin;
    }

    string ans = "";
    int carry = 1;

    while(i >= 0){
        if(carry == 1){
            if(bin[i] == '1'){
                ans += '0';
                carry = 1;
            }else{
                ans += '1';
                carry=0;
                i--;
                break;
            }

        }else
            break;
        i--;
    }

    while(i>=0){
        ans += bin[i];
        i--;
    }

    // cout<<ans<<endl;

    if(carry == 1){
        ans += '1';
    }

    reverse(ans.begin(),ans.end());

    return ans;
}


int solve(string bin){
    int len = bin.length();
    if(len == 1)
        return 0;
    string str = bin;

    int ans = 0;
    int i = len-1;

    while(i>=0){

        // cout<<str<<"  ";
        if(str[i] == '1'){
            str = addBin(str);
            // cout<<"AddBin : ";
            ans++;
        }else{ // even binary number
            str = str.substr(0,str.length()-1);
            ans++;
            // cout<<"Half : ";
        }
        // cout<<str<<endl;
        if(str.length() == 1){
            break;
        }

        i = str.length()-1;
    }

    return ans;
}

int main(){
      
    string input;
    cin>>input;

    cout<<solve(input)<<endl;

    return 0;
}






/*

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1. 




*/