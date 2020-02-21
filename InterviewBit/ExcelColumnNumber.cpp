#include<bits/stdc++.h>
using namespace std;

// Base Conversion Concept
// Like :-   Conveting binary number to decimal number system

int main(){ 

    string str = "AB";

    int len = str.length();

    int ans = 0;

    int p = 0;

    for(int i = len-1;i>=0;i--){
        ans += (str[i]-'A'+1)*pow(26,p);
        p++;
    }

    cout<<ans<<endl;


    return 0;

}   