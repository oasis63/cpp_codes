#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

class Solution {

private: 
    long reverseNumber(int n){
        long rev = 0;
        int rem = 0;
        while(n){
            rem = n%10;
            rev = rev*10 + rem;
            n/=10;
        }
        return rev;
    }

public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int rN = (int) reverseNumber(x);
        // cout<<"reversedNumber "<<rN<<endl;
        // string str = to_string(x);
        // string rstr = str;
        // reverse(rstr.begin(),rstr.end());
        // cout<<str<<"  "<<rstr<<endl;
        return rN == x ? true : false;
    }
};

int main(){

    Solution s;
    int n = 998765432;
    cout<<s.isPalindrome(n)<<endl;
    

    return 0;
}